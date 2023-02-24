#include "./Search.h" 

/*void main(void)
{
    u8 arr[100];
    for(u8 i=1 ; i<=100 ; i++)
    {
        arr[i-1]=i;
    }
    u8 x=linear_search(arr,sizeof(arr)/sizeof(arr[0]),101);
    printf("%d\n",x);
}*/

u8 linear_search(u8 *arr,u8 length,u8 element)
{
     u8 flag=false;
     for(u8 i=0 ; i<length ; i++)
     {
          if(element==arr[i]){flag=i;break;}
     }
     return flag;
}

u8 binary_search(u8 *arr,u8 length,u8 element)
{
    u8 start=0,end=(length-1),mid,flag=false;
    while(!flag)
    {
        mid=(end+start)/2;
        if(arr[mid]==element)flag=mid;
        else
        {
            if(start==end){break;}
            else if(element>arr[mid])start=mid+1;
            else if(element<arr[mid])end=mid-1;
        }
    }
    return flag;
}
u8 jumb_search(u8 *arr,u8 length,u8 element)
{
     u8 jumb=floor(sqrt(length))-1,counter=0,flag=true;
     if(element==arr[counter])flag=counter;
     else
     {
          if(element>arr[counter])
          {
               while(flag)
               {
                    if(counter==(length-1)) flag=false;
                    if(arr[counter]!=element)
                    {
                         if(arr[counter]<element) counter+=jumb;
                         if(arr[counter]>element)
                         {
                              counter-=(jumb-1);
                              for(u8 i=0;i<jumb;i++)
                              {
                                   if(arr[counter]==element){flag=counter;break;}
                                   else flag==false;
                                   counter++;
                              }
                         }
                    }
                    else {flag=counter;break;}
               }
          }
          else flag=false;
     }
     return flag;
}