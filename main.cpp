#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum enLevel { easy = 1 , med = 2 , hard = 3 , mixLevel = 4};

enum enOperation { add = 1 , sub = 2 , mult = 3 , div= 4 , mixOp = 5};

struct stQuesInfo {
    
    short questiontime =0 ;
    short rightanswer =0;
    
};

struct stGameInfo {
        
    string quesLevel ="";
    string opType ="";    
    stQuesInfo QuesInfo ;
};

struct stNums {
    
    int n1 , n2;   
};

int randint(int from , int to ){
    return rand() % (to - from +1)+from;
}

int ReadNum (string msg ){
    
    int num =0;
    cout << msg ;
    cin >> num ;
    
    return num ;
}

enLevel GameLevel (int n ){
    
    switch ( (enLevel)n ){
        
        case enLevel :: easy :{
            return enLevel :: easy;
        }
        case enLevel :: med :{
            return enLevel :: med ;            
        }
        case enLevel :: hard :{
            return enLevel :: hard ;            
        }
        case enLevel :: mixLevel:{
            return enLevel :: mixLevel;
        }
    }
    return enLevel :: mixLevel ; 
}

enOperation GameOp (short n ){
    
     switch ((enOperation) n ){
      
          case enOperation:: add :{          
              return enOperation:: add ;
          }
          case enOperation:: sub :{
              return enOperation:: sub ;
          }
          case enOperation:: mult :{
              return enOperation::mult ;
          }
          case enOperation:: div :{
              return enOperation:: div ;
          }
          case enOperation:: mixOp:{
              return enOperation:: mixOp;
          }
     }    
     return enOperation:: mixOp;
} 

char checkOp (short n ){
    
    char op[4] ={ '+', '-' , '*' , '/' };
    
    switch (GameOp(n)){
        
        case enOperation:: add:{
              return '+';          
        }
        case enOperation:: sub:{
            return '-';
        }
        case enOperation:: mult :{
            return '*';
        }
        case enOperation:: div :{
            return '/';
        }
        case enOperation:: mixOp:{
            return op[randint(0,3)];
        }
       
    default :
            return op[randint(0,3)];   
    }
}

int addition (int n1 , int n2){
        
    return  (n1 + n2) ;
}

int substance (int n1 ,int n2 ){
    
    return (n1 - n2) ;
}

int multiply (int n1, int n2 ){
    
   return n1 * n2 ; 
}

int division (int n1 , int n2){
    
    return (int) n1 / n2 ;
}
//void DisplayQuestion (){
//    
//     int QuesLevel[4] = { addition(2,4)   };
//      
//       
//} 

stNums checkLevel (short lvl, stNums& nums ){
    
    
    switch ( GameLevel(lvl) ){
        
        case enLevel :: easy :{
            nums.n1 = randint(1,10);
            nums.n2 = randint(1,10);
            break;
        }
        case enLevel :: med :{
            nums.n1 = randint(10,80);
            nums.n2 = randint(10,80);
            break;
        }
        case enLevel :: hard :{
            nums.n1 = randint(80,150);
            nums.n2 = randint(80,150);
            break;
        }
        case enLevel :: mixLevel :{
            nums.n1 = randint(1,150);
            nums.n2 = randint(1,150);
            break;            
        }
    }
    return nums ;    
}

int AnswerQues (stNums nums , char op){
    
    switch (op){
        
        case '+':
            return addition(nums.n1,nums.n2) ;
        case '-':
            return substance (nums.n1,nums.n2) ;
        case '*':
            return multiply (nums.n1,nums.n2);
       case '/':
           return division (nums.n1,nums. n2);
    }    
}

bool istrue (int num , int answer){
    
   if (num == answer)
       return true ;
   else 
       return false ; 
}

string Result (stGameInfo GI){
    
    if (GI.QuesInfo.rightanswer >= GI.QuesInfo.questiontime /2 ){        
        return "Pass " ;        
    }
    else {
        return "Failed ";
    }
}

string ques_lvl (short n ,stGameInfo& GameInfo){
    
    if (GameLevel(n) == enLevel :: easy)
        GameInfo.quesLevel ="easy";    
    
    else if (GameLevel(n) == enLevel ::med)
        GameInfo.quesLevel = "medium";
   
    else if (GameLevel(n) == enLevel ::hard)
        GameInfo.quesLevel = "hard";
            
    else if (GameLevel(n) == enLevel :: mixLevel)
       GameInfo.quesLevel ="Mix";     
       
    return GameInfo.quesLevel  ;
    
}

string opType (short n ){
    
    switch ( GameOp(n) ){
        
        case enOperation:: add :
            return " addition ";
            
        case enOperation:: sub :
            return "substraction ";
            
        case enOperation:: mult :
            return "multiply ";
            
        case enOperation:: div :
            return "division ";
            
        case   enOperation:: mixOp:
            return "Mix ";        
    }
}
void printresult (stGameInfo GameInfo, short lvl , short opty){
    
    cout <<"\n _______________________\n";
    cout << "   Finall Result : "<< Result (GameInfo)<<endl; 
    cout <<"________________________\n ";
    cout <<"________________________\n ";
    cout <<" questions number : "<< GameInfo.QuesInfo.questiontime<< endl;
    
    cout <<" right answers : "<< GameInfo.QuesInfo.rightanswer << endl;
    
    cout <<" wrong answers : "<< GameInfo.QuesInfo.questiontime - GameInfo.QuesInfo.rightanswer << endl ;
    
    cout << " Questions level : "<< ques_lvl(lvl,GameInfo) << endl;
    
    cout<<" operation type: "<<opType(opty)<< endl;
    
    cout <<" ________________________\n";
    
}


void printQues (stNums nums , char op){
    
    cout <<"  "<<nums.n1 ;
    cout <<"\n  "<<nums.n2 << op <<endl;
    cout <<"______"<< endl;
}


void StartQues ( short endQu , stGameInfo GameInfo){
    
    short QuesLvl = ReadNum (" enter the level of questions : \n[1].easy \n [2].med  \n [3].hard \n [4].mix : ");
        
    short QuesOp = ReadNum (" enter the operation type of questions :\n [1].addition\n [2].substance \n [3].multiply \n [4].division \n [5].mix: "); 
    
  int answer =0;  
    stNums nums ;
    char Op ='+';
    
   for (short counter=1;counter<=endQu;counter++){
        checkLevel(QuesLvl,nums );
        cout <<"\n  QUESTION [ "<<counter<<"/"<< endQu <<" ] ____________\n";
        cout <<"";
        Op = checkOp(QuesOp) ;
        printQues(nums, Op);
        cout <<"  ";
                
        answer= ReadNum("");
        
        if( istrue(AnswerQues(nums,Op),answer)){
            
            cout <<"\n right answer \n";
            GameInfo.QuesInfo.rightanswer++;
        }
       else {
          cout <<"\n wrong answer \n";      
          cout <<". correct answer : "<<  AnswerQues(nums,Op)<<endl;
       }
    }
    printresult (GameInfo,QuesLvl,QuesOp);
    
}   

void StartGame (){
    
    stGameInfo GameInfo ;
    short playagain =1;
    
    do {
        system ("clear");
        GameInfo.QuesInfo.questiontime =ReadNum(" how many Questions you want to answer: ");    
            
       StartQues(GameInfo.QuesInfo.questiontime, GameInfo);
        
       playagain = ReadNum("\n\n would you like to play another round ? (0/1) : ");
       
    }while( playagain > 0);
    
} 

int main(){
    
   srand((unsigned)time(NULL));
   
   StartGame();
   
   return 0;
}
