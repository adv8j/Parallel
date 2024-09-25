contents = [
    '''for (int i = 0; i < 10; i++){
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
'''

 
]

# Writing each test case into separate files
for idx, content in enumerate(contents, start=1):
    filename = f"input/{idx}.txt"
    with open(filename, "w") as file:
        file.write(content)
