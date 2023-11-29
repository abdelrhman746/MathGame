#include <iostream>
#include <cstdlib>
using namespace std;

enum enScreenColor { Red = 1, Blue = 2, Green = 3, Yellow = 4, Black = 5 };
enum enGameLevel { Easy = 1, Medium = 2, Hard = 3, Mix=4 };
enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, MIX = 5 };

struct stMathGameParameters
{
    int QNumbers;
    int GLevel;
    int OType;
    int Operand1;
    int Operand2;
    int Operation;
    int Result;
    int UserAnswer;
    int QuestionNo;
    int RightAnswers;
    int WrongAnswers;
    char PlayAgain;
};

void RingBill(void)
{
    cout << "\a";
}

void ScreenColor(enScreenColor ScreenColor)
{
    if (ScreenColor == enScreenColor::Red)
    {
        system("color 4F");
    }
    else if (ScreenColor == enScreenColor::Blue)
    {
        system("color 1F");
    }
    else if (ScreenColor == enScreenColor::Green)
    {
        system("color 2F");
    }
    else if (ScreenColor == enScreenColor::Yellow)
    {
        system("color 6F");
    }
    else if (ScreenColor == enScreenColor::Black)
    {
        system("color 0F");
    }
    else
    {
        system("color 3F");
    }
}

int RandomNumber(int From, int To)
{
    //Function to generate a random number

    int randNum = rand() % (To - From + 1) + From;

    return randNum;
}

void GetNumberOfQuestions(int &QNumbers)
{
    cout << "How Many Questions do you want to answer ? ";
    cin >> QNumbers;
}

void GetGameLevel(int &GLevel)
{
    cout << "Enter Questions Level [1] Easy, [2] Medium, [3] Hard, [4] Mix ? ";
    cin >> GLevel;
}

void GetOperationType(int &OType)
{
    cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
    cin >> OType;
}

void GetOperation(int OType, int &Operation)
{
    if (OType == enOperationType::Add)
    {
        Operation = 1;
    }
    else if (OType == enOperationType::Sub)
    {
        Operation = 2;
    }
    else if (OType == enOperationType::Mul)
    {
        Operation = 3;
    }
    else if (OType == enOperationType::Div)
    {
        Operation = 4;
    }
    else if (OType == enOperationType::MIX)
    {
        Operation = RandomNumber(1,4);
    }
}

void GetOperand(int GLevel, int &Operand)
{
    if (GLevel == enGameLevel::Easy)
    {
        Operand = RandomNumber(1, 10);
    }
    else if (GLevel == enGameLevel::Medium)
    {
        Operand = RandomNumber(10, 20);
    }
    else if (GLevel == enGameLevel::Hard)
    {
        Operand = RandomNumber(20, 100);
    }
    else if (GLevel == enGameLevel::Mix)
    {
        Operand = RandomNumber(1, 100);
    }
}


void PrintOperation(int Operation)
{
    if (Operation == enOperationType::Add)
    {
        cout << "+";
    }
    else if (Operation == enOperationType::Sub)
    {
        cout << "-";
    }
    else if (Operation == enOperationType::Mul)
    {
        cout << "*";
    }
    else if (Operation == enOperationType::Div)
    {
        cout << "/";
    }
}

void GetUserAnswer(int &UserAnswer)
{
    cin >> UserAnswer;
}

void GetOperationResult(int Operation,int Operand1,int Operand2,int &Result)
{
    if (Operation == enOperationType::Add)
    {
        Result = (Operand1 + Operand2);
    }
    else if (Operation == enOperationType::Sub)
    {
        Result = (Operand1 - Operand2);
    }
    else if (Operation == enOperationType::Mul)
    {
        Result = (Operand1 * Operand2);
    }
    else if (Operation == enOperationType::Div)
    {
        Result = (Operand1 / Operand2);
    }
}

void PrintGameLevel(int GLevel)
{
    if (GLevel == enGameLevel::Easy)
    {
        cout << "Easy";
    }
    else if (GLevel == enGameLevel::Medium)
    {
        cout << "Medium";
    }
    else if (GLevel == enGameLevel::Hard)
    {
        cout << "Hard";
    }
    else if (GLevel == enGameLevel::Mix)
    {
        cout << "Mix";
    }
}

void PrintOperationType(int OType)
{
    if (OType == enOperationType::Add)
    {
        cout << "+";
    }
    else if (OType == enOperationType::Sub)
    {
        cout << "-";
    }
    else if (OType == enOperationType::Mul)
    {
        cout << "*";
    }
    else if (OType == enOperationType::Div)
    {
        cout << "/";
    }
    else if (OType == enOperationType::MIX)
    {
        cout << "Mix";
    }
}

void PrintUserAnswerResult(int UserAnswer, int Result, int & RightAnswers, int &WrongAnswers)
{
    if (UserAnswer == Result)
    {
        cout << "Right Answer :-)" << endl;
        ScreenColor(enScreenColor::Green);
        RightAnswers++;
    }
    else
    {
        cout << "Wrong Answer :-(" << endl;
        cout << "The right answer is: " << Result << endl;
        RingBill();
        ScreenColor(enScreenColor::Red);
        WrongAnswers++;
    }
}

void PrintQuestions(stMathGameParameters& MathGameParameters)
{
    cout << "Question [" << MathGameParameters.QuestionNo << "/" << MathGameParameters.QNumbers << "]" << endl << endl;
    cout << MathGameParameters.Operand1 << endl;
    cout << MathGameParameters.Operand2;
    PrintOperation(MathGameParameters.Operation);
    cout<< endl;
    cout << "____________________" << endl;
    GetUserAnswer(MathGameParameters.UserAnswer);
    GetOperationResult(MathGameParameters.Operation,MathGameParameters.Operand1,MathGameParameters.Operand2,MathGameParameters.Result);
    PrintUserAnswerResult(MathGameParameters.UserAnswer,MathGameParameters.Result,MathGameParameters.RightAnswers,MathGameParameters.WrongAnswers);
}

void PrintResults(int RightAnswers,int WrongAnswers)
{
    if (RightAnswers >= WrongAnswers)
    {
        cout << "Final Results is Pass :-) " << endl;
        ScreenColor(enScreenColor::Green);
    }
    else
    {
        cout << "Final Results is Fail :-( " << endl;
        RingBill();
        ScreenColor(enScreenColor::Red);
    }
}

void PlayAgain(char &PlayAgain)
{
    cout << "Do you want to play again? [Y/N]" << endl;
    cin >> PlayAgain;
}

void PrintFinalResult(stMathGameParameters &MathGameParameters)
{
    cout << "__________________________________" <<endl<< endl;
    PrintResults(MathGameParameters.RightAnswers,MathGameParameters.WrongAnswers);
    cout << "__________________________________" << endl;
    cout << "Number Of Questions     :" << MathGameParameters.QNumbers << endl;
    cout << "Question Level          :";
    PrintGameLevel(MathGameParameters.GLevel);
    cout<< endl;
    cout << "Operation Type          :";
    PrintOperationType(MathGameParameters.OType);
    cout << endl;
    cout << "Number of Right Answers :" << MathGameParameters.RightAnswers << endl;
    cout << "Number of Wrong Answers :" << MathGameParameters.WrongAnswers << endl;
    cout << "__________________________________"<<endl;
}

void ResetScreen()
{
    system("cls");
    ScreenColor(enScreenColor::Black);
}

void MathGame()
{
    stMathGameParameters MathGameParameters;
    
    do
    {
        ResetScreen();
        MathGameParameters.Operand1 = 0;
        MathGameParameters.Operand2 = 0;
        MathGameParameters.Operation = 0;
        MathGameParameters.RightAnswers = 0;
        MathGameParameters.WrongAnswers = 0;
        GetNumberOfQuestions(MathGameParameters.QNumbers);
        GetGameLevel(MathGameParameters.GLevel);
        GetOperationType(MathGameParameters.OType);
        MathGameParameters.QuestionNo = 0;
        int Counter = MathGameParameters.QNumbers;
        while (Counter > 0)
        {
            MathGameParameters.QuestionNo++;
            GetOperation(MathGameParameters.OType,MathGameParameters.Operation);
            GetOperand(MathGameParameters.GLevel,MathGameParameters.Operand1);
            GetOperand(MathGameParameters.GLevel, MathGameParameters.Operand2);
            PrintQuestions(MathGameParameters);
            Counter--;
        }
        PrintFinalResult(MathGameParameters);
        PlayAgain(MathGameParameters.PlayAgain);
    }while(MathGameParameters.PlayAgain == 'Y' || MathGameParameters.PlayAgain == 'y');
    
}

int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    MathGame();


    return 0;
}