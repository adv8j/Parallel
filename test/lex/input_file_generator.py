# Contents extracted from the previous step
contents = [
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
    '''@Properties
{
    int x = 5;
    int y = 10;
}
''',
    '''@Order order
''',
    '''@Properties{@Order{
    t1->t2, t3->t4, t6->, t9;;
    t2->t6->t8, t9,t10->all;}}
''',
    '''@TaskGroup g1
{@Properties{@Mem{var1->t1;var2->t2mut;var3->t3 mut;}}}
''',
    '''@Mem
{
    R2->R3;
}
''',
    '''@Mem
{
    R2        -  
     >
    R3
    ;
}
''',
    '''unsafe@Mem{R2->R3;}
''',
    '''@Supervisor{
    call = call t2;
    call.join();
}
''',
    '''@Task
{
    int ct = 5;
    for i in 1..ct;
}
''',
    '''@Task
{
    .ct <   -
    5;
    .wt{someIdentifier, 56};
}
''',
    '''@Task
{
    .ct(all)->5;.wt(t6,9);
}
''',
    '''@TaskGroup(log="file.txt")
''',
    '''@TaskGroup(log="file.txt)
{
    // " // this gives error
}
''',
    '''@TaskGroup(log="file.txt", k=96)
''',
    '''@TaskGroup(log="file.txt",, k=96)
''',
    '''// \\n this should ideally only give int, token and ; as tokens
int token;
''',
    '''@parallel(shared=[sum], private=[c, d], threads=4, schedule='static')
for c in 0..100 {
    sum += someArray(a[d]);
}
''',
    '''@parallel(reduction=[+:sum])
for c in 0..100 {
    sum += someArray(a[d]);
}
''',
    '''@parallel(threads='4')
{
    process_data(data);
}
''',
    '''parallel(threads=4) {
    process_data(data);
}
'''
]

# Writing each test case into separate files
for idx, content in enumerate(contents, start=1):
    filename = f"{idx}.txt"
    with open(filename, "w") as file:
        file.write(content)
