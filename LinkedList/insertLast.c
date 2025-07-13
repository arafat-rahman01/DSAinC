#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void appendNode(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, value;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        appendNode(&head, value);
    }

    printf("\nLinked List: ");
    printList(head);

}


/* কোড এবং লাইন-বাই-লাইন ব্যাখ্যা
হেডার ফাইল
c

Copy
#include<stdio.h>
#include<stdlib.h>
stdio.h: ইনপুট-আউটপুট ফাংশন (যেমন printf, scanf) ব্যবহারের জন্য।
stdlib.h: মেমরি অ্যালোকেশন ফাংশন (যেমন malloc) ব্যবহারের জন্য।
নোড স্ট্রাকচার
c

Copy
struct Node{
    int data;
    struct Node* next;
};
এখানে একটি Node নামে স্ট্রাকচার ডিফাইন করা হয়েছে।
data: নোডে একটি ইন্টিজার মান সংরক্ষণ করবে।
next: পরবর্তী নোডের ঠিকানা সংরক্ষণ করবে (পয়েন্টার)।
এটি লিঙ্কড লিস্টের প্রতিটি নোডের গঠন।
নতুন নোড তৈরি ফাংশন
c

Copy
struct Node* createNode(int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}
লাইন ১: createNode ফাংশন একটি নতুন নোড তৈরি করে। এটি একটি ইন্টিজার value প্যারামিটার হিসেবে নেয়।
লাইন ২: malloc দিয়ে নতুন নোডের জন্য মেমরি বরাদ্দ করা হয়। sizeof(struct Node) নোডের সাইজ নির্ধারণ করে। এটি struct Node* টাইপে কাস্ট করা হয়।
লাইন ৩: নতুন নোডের data ফিল্ডে value সেট করা হয়।
লাইন ৪: নতুন নোডের next ফিল্ড NULL সেট করা হয়, কারণ এটি এখনও কোনো নোডের সাথে সংযুক্ত নয়।
লাইন ৫: নতুন নোডের পয়েন্টার ফেরত দেওয়া হয়।
নোড যোগ করার ফাংশন
c

Copy
void appendNode(struct Node ** head, int value){
    struct Node* newNode=createNode(value);
    if(*head==NULL){
        *head=newNode;
        return;
    }
    struct Node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}
লাইন ১: appendNode ফাংশন লিস্টের শেষে নতুন নোড যোগ করে। এটি head (লিস্টের শুরুর পয়েন্টার) এবং value নেয়।
**head ব্যবহার করা হয় কারণ আমরা head এর মান পরিবর্তন করতে চাই (যদি লিস্ট খালি থাকে)।
লাইন ২: createNode ফাংশন কল করে নতুন নোড তৈরি করা হয়।
লাইন ৩-৫: যদি লিস্ট খালি থাকে (*head==NULL), তাহলে নতুন নোডটি head হিসেবে সেট করা হয় এবং ফাংশন থেকে ফেরত যায়।
লাইন ৬: একটি অস্থায়ী পয়েন্টার temp তৈরি করা হয়, যা head থেকে শুরু হয়।
লাইন ৭-৮: while লুপ দিয়ে লিস্টের শেষ নোডে পৌঁছানো হয়, যেখানে next হলো NULL।
লাইন ৯: শেষ নোডের next ফিল্ডে নতুন নোডের পয়েন্টার সেট করা হয়।
লিস্ট প্রিন্ট করার ফাংশন
c

Copy
void printList(struct Node * head){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}
লাইন ১: printList ফাংশন লিস্টের সব নোড প্রিন্ট করে। এটি head পয়েন্টার নেয়।
লাইন ২: একটি অস্থায়ী পয়েন্টার temp তৈরি করা হয়, যা head থেকে শুরু হয়।
লাইন ৩-৫: while লুপ দিয়ে প্রতিটি নোডের data প্রিন্ট করা হয়, তারপরে "->" প্রিন্ট হয়। temp পরবর্তী নোডে যায়।
লাইন ৬: লিস্টের শেষে NULL প্রিন্ট করা হয়।
মেইন ফাংশন
c

Copy
int main(){
    struct Node* head=NULL;
    int n, value;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        appendNode(&head,value);
    }
    printList(head);
}
লাইন ১: main ফাংশন প্রোগ্রামের এন্ট্রি পয়েন্ট।
লাইন ২: head পয়েন্টার ডিফাইন করা হয় এবং NULL সেট করা হয় (লিস্ট খালি)।
লাইন ৩: n (নোডের সংখ্যা) এবং value (নোডের ডেটা) এর জন্য ভেরিয়েবল ডিফাইন করা হয়।
লাইন ৪: ইউজারের কাছ থেকে n ইনপুট নেওয়া হয়।
লাইন ৫-৭: একটি for লুপ n বার চলে। প্রতিবার:
ইউজারের কাছ থেকে একটি value ইনপুট নেওয়া হয়।
appendNode ফাংশন কল করে লিস্টে নতুন নোড যোগ করা হয়।
লাইন ৮: printList ফাংশন কল করে পুরো লিস্ট প্রিন্ট করা হয়।
উদাহরণ ইনপুট এবং আউটপুট
ইনপুট:

text

Copy
5
1 2 3 4 5
প্রথমে n=5 ইনপুট দেওয়া হয়।
তারপর ৫টি মান: 1, 2, 3, 4, 5।
প্রতিটি মান লিস্টের শেষে যোগ হয়।
আউটপুট:

text

Copy
1->2->3->4->5->NULL
লিস্টের প্রতিটি নোডের data প্রিন্ট হয়, তাদের মধ্যে "->" দিয়ে সংযুক্ত, এবং শেষে NULL।*/
