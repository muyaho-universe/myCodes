package edu.handong.csee.java.pracitce;

public class Person{

    public int age = 30;
    public int weight;

    public static void main(String[] args) {
        Person myRun = new Person();
        myRun.run();
    }

    public void run(){
        Person demo = new Person();
        demo.setAge(50);
    }

    public void setAge(int a){
        age = a;
        System.out.println("Age has been changed " + age);
    }
}