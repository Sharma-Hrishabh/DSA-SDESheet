Node* mergeLists(Node* head1, Node* head2){
    if(!head1) return head2;
    if(!head2) return head1;
    
    Node* head=NULL;
    Node* tail=NULL;
    //set head & tail
    if(head1->data<=head2->data){
        head=head1;
        head1=head->bottom;
        tail=head;
    }
    else{
        head=head2;
        head2=head2->bottom;
        tail=head;
    }

    while(head1!=NULL && head2!=NULL){
        if(head1->data<=head2->data){
            tail->bottom=head1;
            head1=head1->bottom;
            
        }
        else{
            tail->bottom=head2;
            head2=head2->bottom;
        }
        tail=tail->bottom;
        
    }
    
    while(head1!=NULL){
        tail->bottom=head1;
        head1=head1->bottom;
        tail=tail->bottom;
    }
    
    while(head2!=NULL){
        tail->bottom=head2;
        head2=head2->bottom;
        tail=tail->bottom;
    }
    
    return head;
}

Node *flatten(Node *root)
{
   // Your code here
   if(!root) return NULL;
   if(root->next==NULL) return root;
   
   root->next = flatten(root->next);
   
   return mergeLists(root,root->next);


}