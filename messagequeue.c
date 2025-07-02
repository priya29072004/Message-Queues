// Sender


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
 struct buffer
 {
   long type;
   char text[100];
 
 };
 
 int main()
 {
   key_t key=ftok("myfile.txt",65);
   int mesgid=msgget(key,0666 | IPC_CREAT);
   struct buffer message;
   message.type=1;
   printf("message queue form writer\n");
   fgets(message.text,sizeof(message.text),stdin);
   msgsnd(mesgid,&message,sizeof(message.text),0);
   printf("message sent \n");
   return 0;
 
 
 }
 
 
 // Receiver
 
 #include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>

 struct buffer
 {
   long type;
   char text[100];
 
 };
 
 int main()
 {
   key_t key=ftok("myfile.txt",65);
   int mesgid=msgget(key,0666 | IPC_CREAT);
   struct buffer message;
   msgrcv(mesgid, &message, sizeof(message.text), 1, 0);
    printf("Received: %s", message.text);
     msgctl(mesgid, IPC_RMID, NULL);
   return 0;
 
 
 }
 
 
 // Output in sender terminal
 
 /*
 
 message queue form writer
hello from sender
message sent 


//Output in receiver terminal

Received: hello from sender

*/


