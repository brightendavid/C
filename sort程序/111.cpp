 FILE *fp=fopen("test.txt","r");    //����һ��fp�ļ�����ָ����ֻ����ʽ�򿪵��ļ���test.txt��
 
    int x;       
     
    float y,z; 
 
    fscanf(fp, "%d %f %lf", &x, &y, &z); //���ո�ʽ�Դ˴��ļ��ж�ȡ���ݲ���ֵ��x, y, z
 
    printf(" x = %d\n y = %f\n z = %lf",x, y, z);     
 
    fclose(fp);             //�ر��ļ���
 
    return 0;        

