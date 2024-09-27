contents = [
    '''int a=10; //single line comment
''',
'''/*this is 
multi line cooment*/
a=20;
''',
'''int a; 
char c='a';
char c=23;
int v=56;
long num=10000000;
bool flag=true;
bool flag2=1;
float pi=3.14;
x=10;

''',
'''a+3;
b=2+3*5;
c=(3<4)&&(6>4);
w+=40;
mo%=10;
-check;
check=(4!=5);
''',
'''
int[5] arr={1,2,3,4,5};
x= arr[0];
arr[4]=6;
y=arr[-1]; 
z=arr[5];
arr = 1..n;
''',
'''
string s="How are you?";
string ab="";
z="checking";

lenOfz=z.length();
fourthchar=s[4];

areEqual=("check"=="CHECK");
isgreater=("check">"CHECK");
''',

'''for (int i = 0; i < 10; i++){
        sum=sum+i;
    }
''',
'''for (int i = 0; i < 10; ){
        sum=sum+i;
    }
''',
'''for (a in 3..8){
    sum=sum+a;
}
''',
'''for (z in myarr){
    sum=sum+z;
}
''',
'''if(a>b){
        sum=sum-9;
    }
''',
'''if(a>b){
        sum=sum-9;
    }
    else{
        sum=sum+9;
    }
''',
'''if(a>b){
        if(2<4){
            d=d+2;
        }
        else if(value==true){
            d=d-2;
        }
        else{
            
        }
    }
    else{
        sum=sum+9;
    }
''',
'''func myfunc int (int a , char c){
        a=b;
        int e=10;
        return e;
        
    }
''',
'''func myfunc int (){
        return e+3;
        
    }
''',

'''
func example_function int (int a,int b){
    return a+b;
}
a = 1;
b = 2;
X = example_function(a,b);

''',

'''
int a = 10;
int& ref = a;
ref = 20; 


''',
'''
struct Person {
    // Data members
        int age;
        float height;
};

struct Person person = {45, 5.3};

person.age = 30;
person.height = 1.75;
X = func();
X = person.age;

''',

'''@TaskGroup g1
{
    @Task t1
    {
        for (int i = 0; i < 10; i++);
    }
}
''',
    '''@TaskGroup g1
{
    int x = 5, y=2;y=3;
    y = 4;
    _task;
    @Task t1
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++);
        }
    }
}
''',
    '''@TaskGroup g1
{
    @TaskGroup g2
    {
        @ Task t1
        {
            _task;
        }
    }
}
''',
'''@TaskGroup g1
{
    @Task t1
    {}
    @Task t2
    {}
    @Task t3
    {}
    @Properties
    {
    
    }
}
''',
'''@TaskGroup g1
{
    @Task t1
    {}
    @Properties
    {
        @Order{
            all->t1;
            t1->t2,t3;
            t3->all;
        }
    }
}
''',
'''@TaskGroup g1
{
    @Task t1
    {}
    @Properties
    {
        @Mem{
            a->t1,t2 mut t3;
        }
    }
}
'''

 
]

# Writing each test case into separate files
for idx, content in enumerate(contents, start=1):
    filename = f"input/{idx}.txt"
    with open(filename, "w") as file:
        file.write(content)
