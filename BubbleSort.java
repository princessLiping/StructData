package com.sort.liping;
import java.lang.reflect.Array;
import java.sql.SQLOutput;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Date;

public class BubbleSort {
    public static void main(String [] a){
      //  int arr []={9,5,4,10,2,6,3};
        //测试：创建80000个随机数组
        int [] array=new int[15];
        for(int i=0;i<array.length;++i){
            array[i]=(int)(Math.random()*6666);
        }
        timeAll();
        bubbleSort(array);
        outPut(array);
        timeAll();
    }
    public static void bubbleSort(int arr []){
        int temp;
        boolean flag=false;//标识变量，表示是否交换过
        for(int i=0;i<arr.length-1;++i){
            for(int j=0;j<arr.length-i-1;++j){
                if(arr[j]>arr[j+1]){
                    flag=true;
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
            if(!flag){//再一次排序中，一次交换都没有发生,!flag等价于flage==false，也就相当于
                break;
            }else{
                flag=false;//交换后需要还原，对下次排序在进行判断
            }
        }
    }
    public static void outPut(int arr[]){
            System.out.println(Arrays.toString(arr));
    }
    public static void timeAll(){
        Date data=new Date();
        SimpleDateFormat simpleDateFormat=new SimpleDateFormat("YYYY-MM-dd HH:mm:ss");
        String date1Str=simpleDateFormat.format(data);
        System.out.println("现在的时间是"+date1Str);
        //排序前的时间
        /*
        long totalMilliseconds1= System.currentTimeMillis();
        System.out.println(totalMilliseconds1);
        //排序后的时间
        long totalMilliseconds2= System.currentTimeMillis();
        System.out.println(totalMilliseconds2);
         */
    }

}
