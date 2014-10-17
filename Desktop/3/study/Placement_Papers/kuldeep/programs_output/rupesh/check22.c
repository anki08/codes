main(){
 char str[]="ram rami khel raha tha...rami ram ko kha rahi thi..";
 char pattern[]="rami"; 
 int i,j,k,count=0;
 for(i=0;i<strlen(str);i++){
 	for(j=i,k=0;(pattern[k]!='\0') && (str[j]==pattern[k]);j++,k++);
	if(pattern[k]=='\0')
		count++;	
 }
 printf("\n count = %d\n",count); 
}

