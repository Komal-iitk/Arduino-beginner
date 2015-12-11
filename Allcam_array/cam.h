
void cam0all()
{

a++;

if(a==10)
{
a=1;
cout<<"a = "<<a<<endl;
}
else
{
cout<<"a = "<<a<<endl;
}

Mat tempFrame0;
cap0.grab();
cap0.retrieve(tempFrame0);

pthread_mutex_lock(&frameLocker0);
frame0[a] = tempFrame0;
pthread_mutex_unlock(&frameLocker0);

writer0.write(frame0[a]);
}

//////////////////////////////////////////////////////////////////////

void cam1all()
{

b++;

if(b==10)
{
b=1;
cout<<"b = "<<b<<endl;
}
else
{
cout<<"b = "<<b<<endl;
}

Mat tempFrame1;
cap1.grab();
cap1.retrieve(tempFrame1);

pthread_mutex_lock(&frameLocker1);
frame1[b] = tempFrame1;
pthread_mutex_unlock(&frameLocker1);

writer1.write(frame1[b]);
}

/////////////////////////////////////////////////////////////////////////

void cam2all()
{

c++;

if(c==10)
{
c=1;
cout<<"c = "<<c<<endl;
}
else
{
cout<<"c = "<<c<<endl;
}

Mat tempFrame2;
cap2.grab();
cap2.retrieve(tempFrame2);

pthread_mutex_lock(&frameLocker2);
frame2[c] = tempFrame2;
pthread_mutex_unlock(&frameLocker2);

writer2.write(frame2[c]);
}

/////////////////////////////////////////////////////////////////////////

void cam3all()
{

d++;

if(d==10)
{
d=1;
cout<<"d = "<<endl;
}
else
{
cout<<"d = "<<endl;
}

Mat tempFrame3;
cap3.grab();
cap3.retrieve(tempFrame3);

pthread_mutex_lock(&frameLocker3);
frame3[d] = tempFrame3;
pthread_mutex_unlock(&frameLocker3);

writer3.write(frame3[d]);
}

