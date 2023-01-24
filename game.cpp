/****************************************************************************
Jared Falcon
CS211
Queue application
Template written by Kazumi Slott
10/13/2020

To compile:
g++ -pthread game.cpp queue.cpp

This program will ask the user to answer math questions (add, sub, mult, div).
The queue will have 3 questions before the game starts. After the game starts, a new question
will be added every 1 second if the level is 5, 2 seconds if the level is 4, .. 5 seconds if the level is 1.
The user will be asked to choose a level from 1 to 5 before the game starts.
A question for the user to answer will be removed from the front of the queue. The user will be asked to answer
the same question until he gives the correct answer. After he gives a correct answer, the next question will be removed from the front of
the queue.

When the queue grows to have 10 questions (the queue is full), the game ends and the user loses (he was too slow doing the math). 
When the queue becomes empty, the game ends and the user wins (he was quick doing the math).
When the user answers 100 questions correctly, the game ends and the user wins (the queue never became empty or full).

This program uses one thread to add new questions to the queue and another to let the user 
enter math questions.
*****************************************************************************/ 

#include <time.h>
#include <iostream>
#include <pthread.h>
#include <cstdlib>
#include "/cs/slott/cs211/checkInput.h"
#include "queue.h" //your queue class
using namespace std;

/*
******************************
Place the following code in queue.h
Then comment this section. 
********************************
//create an enumuration type
???? op {ADD, SUB, MULT, DIVI};

//create a struct that will have an operand, a operator, another operand
????? expr
{
  int oprd1;
  op oprt;
  int oprd2;
};
*******************************
Place the above code to queueu.h
*******************************
*/

//prototypes
void *answerQuestion(void* data);
void *addQuestion(void* data);
int correctAnswer(int op1, char optr, int op2);
char getOperator(op o);
expr makeQuestion();

//global - easier to share them between threads
Queue q; //create a queu object. the queue will store math questions
bool win; //set to true if win, false if lose
int numCorrect = 0; //the number of correct questions the user answered
pthread_mutex_t lock; //used to lock a part of code where a shared resource (q) 
                      //is updated by a thread
int level;//level of difficulty (1 for easy/slot, 5 for hard/fast)
int ar[] = {5, 4, 3, 2, 1};//will be able to access the different seconds based on level 
int main()
{
  //get a different sequence of random numbers in each run
  // ??????????
  srand(time(NULL));

  //adds 3 questions into the rear of the queue 
  expr e;
  e = makeQuestion();
  q.add(e);
 
  e = makeQuestion();
  q.add(e);

  e = makeQuestion();
  q.add(e);

  //?????
  // ?????
  //?????
 
  cout << "Which level do you want to try? 1 (easy) to 5 (hard): ";
  //level 1 will add a new question every 5 seconds. If level 2, every 4 seconds. If level 5, every 1 second.
  level = getData(1, 5, "Invalid level. Enter 1 to 5: "); //from checkInput.h

  
  //initialize the mutex
  if (pthread_mutex_init(&lock, NULL) != 0)
    {
      cout << "Creating a mutext failed." << endl;
      return 1; //ending the program. 1 is an error code passed to the operating system
    }

  //delcare 2 threads. first thread to add new questions and second for the user to answer questions.
  pthread_t tAddQues, tAns;

  //thread to add new qustions to the rear of the queue
  pthread_create(&tAddQues, NULL, &addQuestion, NULL);

  //thread for the user to answer questions removed from the front of the queue
  pthread_create(&tAns, NULL, &answerQuestion, NULL);
 

  //wait for the thread to come back from addQuestion()
  pthread_join( tAddQues, NULL);

  //wait for the thread to come back from answerQuestion()
  pthread_join(tAns, NULL);

  //win is set to true in answeQuestion() - if the user answers quickly and the queue gets empty or he answers 100 questions correctly, the user wins the game
  if(win == false)
    cout << "You lose" << endl;
  else //if the user doesn't answer questions quick enough and the queue grows to have 10 questions, he loses.
    cout << "You win!" << endl;

    cout << "You answered " << numCorrect << " questions correctly." << endl;

  return 0;
}
/*******************************************************************
This function will add a new question to the queue based on the level
the user decides. It will only keep making questions if the size of the
queue is not 10, empty or if the user answers 100 questions. 
 *****************************************************************/
void *addQuestion(void* data)
{
    expr newQ;//a new question to be added
    
    clock_t endWait;
    //a new question will be added to the queue every 1 second if the level is 5, 
    //2 seconds if the level is 4, .. 5 seconds if the level is 1.
    clock_t waitTime = CLOCKS_PER_SEC * ar[level-1]/4.0;//use level to determine the amount of time per question 
    endWait = clock() + waitTime;//waits for whatever level was chosen 
    //cout << "here add question" << endl;

    //as soon as the queue grows to have 10 questions(full), gets empty or the user answers 100 questions correctly, the game ends
    while(q.getSize() < 10 && !q.isEmpty() && numCorrect < 100)//test
	  {
	    //it is time to add a new question to the queue
	    //cout << "here before clock" << endl;
	    if(clock() >= endWait)
	      {
		//create a new question
		//?????????????????
		//cout << "Here in the first while loop" << endl;
		newQ = makeQuestion();//make new question
		
		//lock the code so this thread has exclusive access to the queue while updating
		pthread_mutex_lock(&lock);
		
		//add the new question to the rear of the queue
		q.add(newQ);
		
		pthread_mutex_unlock(&lock); //unlock the exclusive access so the other thread 
		                             //can access the queue now
		//reset the end wait time
		//????????????????
		endWait = clock() + waitTime;
	      }
	  }
}
/************************************************************
This function will allow us to answer the questions from the queue.
it will end once the queue size grows to 10, its empty , or the 
user answers 100 questions. This will remove a question from infront
of the queue and display it for the user to answer. If its wrong they 
have to try again. At the end of the function the win variable
will be set to true or false depending whether the user doesnt take 
too long or answers quick enough.
 ************************************************************/
void *answerQuestion(void* data)
{
  int answer,correct;//input answer and store the correct answer
  int op1, op2;//stores left and right operator
  char opr;//stores + = / * 
  expr ep;//will store our expression
  
  //  cout << "Here answer q " << endl;
  //as soon as the queue grows to have 10 questions(full), gets empty, or the user answers 100 questions correctly, the game ends
  while(q.getSize() < 10 && !q.isEmpty() && numCorrect < 100)//test!!!!
    {
      //get the question from the front of the queue
      //lock the code so this thread has exclusive access to the queue while updating
      
      //  cout << "Here second loop" << endl;
      pthread_mutex_lock(&lock);

      //???????????
      ep = q.remove();//remove the first expression and store it

      pthread_mutex_unlock(&lock); //unlock the exclusive access so the other thread 
	                           //can access the queue now

      op1 = ep.oprd1;//store the first operand
      
      opr = getOperator(ep.oprt);//convert from enum to char and store in opr
      
      op2 = ep.oprd2;//store the second operand

      //get the answer to the question
      correct = correctAnswer(op1, opr, op2);
 
      //ask the usert to enter the user's answer
      cout << op1 << " " << opr << " " << op2 << " = ";
      //cout << ????? << " = "; //Show the expression struct at once
      cin >> answer;

      //as long as the user's answer is wrong, she/he will have to retry answering the same question
      while(answer != correct && q.getSize() < 10 && !q.isEmpty())//test!!!
	{
	  cout << "WRONG. try again. " <<  op1 << " " << opr << " " << op2 << " = ";
	  //cout << "WRONG. try again. " <<  ??????  << " = ";  //Show the expression struct
	  cin >> answer;
	}
      //the user's answer was correct. the number of correct increases 
      if(answer == correct)
	numCorrect++;
    }
  //  cout << " out of the answer while loop" << endl;
  //if the queue grows to have 10 questions, the user loses the game
  //if the queue gets empty or the suer answers 100 questions correctly, the user wins the game
  if(q.getSize() == 10)
     win = false;
  else 
     win = true;
}
/***********************************************
This function converts an enum value to char.
************************************************/
char getOperator(op o)
{
  switch(o)//switch for the enum op and returns the operator symbol as char 
    {
    case ADD: return '+';
    case SUB: return '-';
    case DIV: return '/';
    case MULT: return '*';
    }
}

/*********************************************
op1 is the left operand
optr is the operator
op2 is the right operand

This function will return the correct answer and
compare it to the users answer
 ********************************************/
int correctAnswer(int op1, char optr, int op2)
{
  switch(optr)//switch for the different operators and returns answer
    {
    case '+': return op1 + op2;
    case '-': return op1 - op2;
    case '/': return op1 / op2;
    case '*': return op1 * op2;
    }
}
/******************************************************
This fucntion creates a question and returns a struct while having 
specific condtions for the different operations that will 
be performed. It will also switch operands if the right operand
is bigger than the left. 
******************************************************/
expr makeQuestion()
{
  int temp;//stores temp variable, an operand
  expr e;//struct to be returned
  e.oprt = (op)(rand()%4); //0 for add, 1 for sub, 2 for mult, 3 for divi

  if(e.oprt == MULT) //if the operator is multiplication, make operands between 1 and 20 for the first operand and between 1 and 10 for the second operand.
                     // (large operands would make multiplication hard.)
    {
      e.oprd1 = rand() % 20 + 1 ; //create a random number between 1 and 20
      e.oprd2 = rand() % 10 + 1;//create a random number between 1 and 10
    }
  else //the operator is add, sub or divi. Make operands between 1 and 100
    {
      e.oprd1 = rand() % 100 + 1;//create a randowm number between 1 and 100
      e.oprd2 = rand() % 100 + 1; //create a randowm number between 1 and 100

      //if the operator is sub or division, the first operand should be greater than or equal to the second operator (otherwise the calulation
      //would the too difficult for SUB and too easy for DIVI. 
      if(e.oprt == SUB || e.oprt == DIV)
	{
	  if(e.oprd1 < e.oprd2) //if the second operand is larger, swap operand1 and operand2
	    {
	      temp = e.oprd1;//store left op1 in temp 
	      e.oprd1 = e.oprd2;//store right in old left op1
	      e.oprd2 = temp;//store op1 into old op2
	    }
	}
    }
 
  return e;//return struct
}

/**********************************************************************************************
You need to create the following opoerator overloading function in queue.cpp above displayAll().

Create this operator overloading function to show an expression at once in the following format
8 + 3
***********************************************************************************************/
/*
????? operator<<(?????)
{
   ?????
}
*/
