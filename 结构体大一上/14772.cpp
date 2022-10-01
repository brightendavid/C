 void Union(LinkList &A,LinkList &B){
 	
 	if(A->next==NULL||B->next==NULL)
 		return ;
 		
 	LinkList pa=A->next;
	LinkList pb=B->next;
	LinkList r=A;
	LinkList sa;
	LinkList sb;
	A->next=NULL;
	
	while(pa&&pb)
	{
		if(pa->data==pb->data)
		{
			sa=pa->next;
			sb=pb->next;
			pa->next=r->next;//β�巨
			r->next=pa;
			r=pa;
			pa=sa;
			free(pb);
			pb=sb;
		}
		else if(pa->data<pb->data)
		{
			sa=pa->next;
			free(pa);
			pa=sa;
		}
		else
		{
			sb=pb->next;
			free(pb);
			pb=sb;
		}
	}
	
	while(pa)
	{
		sa=pa->next;
		free(pa);
		pa=sa;
	}
	
	while(pb)
	{
		sb=pb->next;
		free(pb);
		pb=sb;
	}
	
	free(B);
 	r->next=NULL;

