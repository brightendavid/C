 FILE *fp=fopen("test.txt","r");    //声明一个fp文件流，指向以只读方式打开的文件”test.txt”
 
    int x;       
     
    float y,z; 
 
    fscanf(fp, "%d %f %lf", &x, &y, &z); //按照格式以此从文件中读取数据并赋值给x, y, z
 
    printf(" x = %d\n y = %f\n z = %lf",x, y, z);     
 
    fclose(fp);             //关闭文件流
 
    return 0;        

