C++编程语言中有一种叫做new的二维数组，它的应用方式比较灵活，可以有多种方法来帮助我们实现一些特定功能。在这里我们将会总结几种C++二维数组new的应用方式，来进行逐一的点评。

C++二维数组new应用方式一：

A (*ga)[n] = new A[m][n];   
...   
delete []ga;  
缺点：n必须是已知

优点：调用直观，连续储存，程序简洁(经过测试，析构函数能正确调用)

C++二维数组new应用方式二：

A** ga = new A*[m];   
for(int i = 0; i < m; i++)   
ga[i] = new A[n];   
...   
for(int i = 0; i < m; i++)   
delete []ga[i];   
delete []ga;  
缺点：非连续储存，程序烦琐，ga为A**类型

优点：调用直观，n可以不是已知

C++二维数组new应用方式三：

A* ga = new A[m*n];   
...   
delete []ga;  
缺点：调用不够直观

优点：连续储存，n可以不是已知

C++二维数组new应用方式四：

vector > ga;   
ga.resize(m); //这三行可用可不用   
for(int i = 1; i < n; i++) //   
ga[i].resize(n); //   
...  
缺点：非连续储存，调试不够方便，编译速度下降，程序膨胀(实际速度差别不大)

优点：调用直观，自动析构与释放内存，可以调用stl相关函数，动态增长

C++二维数组new应用方式五：

vector ga;   
ga.resize(m*n);  
方法3,4的结合

C++二维数组new应用方式六：

2的改进版

A** ga = new A*[m];   
ga[0] = new A[m*n];   
for(int i = 1; i < m; i++)   
ga[i] = ga[i-1]+n;  
优点:连续存储,n可以不是已知,析构方便,猜想只需delete [] ga;