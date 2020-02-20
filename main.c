#include<stdio.h>
#include<stdlib.h>


typedef struct node{
  int value;
  struct node* right;
  struct node* left;
}Node;

Node* treeInicialize(){
  return NULL;
}


//basicamente aqui eu passo como parametro a raiz da arvore
//e o valor que desejo inserir no Nó.
//incialmente eu verifico se a raiz é nula, se for nula, eu
//crio um Nó aux com malloc, coloco as raizes direita e //esquerda como NULL e adciono o valor no nó.
//por fim, eu retorno aux.

//No caso da root não ser nula, eu verifico se o valor a ser 
//inserido é maior ou menor que o value dentro do Nó.
// sendo maior eu adciono a direita, sendo menor, adiocno a 
//esquerda. Para adcionar, eu chamo recursivamente a função
// de inserir, passando como parametro a raiz direita ou 
//esquerda.

Node* insertTree(Node* root, int value){

  if(root==NULL){
    Node* aux=(Node*)malloc(sizeof(Node));
    aux->left=NULL;
    aux->right=NULL;
    aux->value=value;
    return aux;
  }else{
    if(root->value > value){
      root->left=insertTree(root->left, value);
    }else if(root->value < value){
      root->right=insertTree(root->right,value);
    }
  }

  return root;
}


//Aqui eu verifico se a raiz não é nula e printo o valor da 
//raiz, depois chamo recursivamente a função para as raizes
//direita e esquerda.
void printTree(Node* root){
  if(root!=NULL){
    printf("%i ",root->value);
    printTree(root->right);
    printTree(root->left);
  }
}

void treeFree(Node* root){
  if(root!=NULL){
    treeFree(root->right);
    treeFree(root->left);
    free(root);
  }
}

Node* treeSearch(Node* root, int value){
	
  if(root!=NULL){
    if(root->value==value){
      return root;
    }else{
      if(value > root->value){
        return treeSearch(root->right, value);
      }else if(value < root->value){
        return treeSearch(root->left,  value);
      }
    }
  }

}

Node* treeSearchMin(Node* root){
	
	Node* aux=root;
	if(aux!=NULL){
		while(aux->left!=NULL){
			aux=aux->left;
		}
		return aux;		
	}
	return NULL;
}

Node* treeRemove(Node* root, int value){
  if(root!= NULL){
    if(value > root->value){
      root->right=treeRemove(root->right, value);
    }else if(value < root->value){
      root->left=treeRemove(root->left, value);
    }else{
      if(root->right==NULL && root->left==NULL){
        free(root);
        return NULL;
      }else if(root->right==NULL && root->left!=NULL){
        Node* aux=root->left;
        free(root);
        return aux;
      }else if(root->right!=NULL && root->left==NULL){
        Node* aux=root->right;
        free(root);
        return aux;
      }else{
        Node* auxiliar=treeSearchMin(root->right);
        int valor=auxiliar->value;
        root=treeRemove(root,valor);
        root->value=valor;
        return root;
      }
    }
    return root;
  }

	return NULL;
}


  main(){
	Node* root;
  root=treeInicialize();
  root=insertTree(root, 15);
  root=insertTree(root, 20);
  root=insertTree(root, 5);
  root=insertTree(root, 13);
  root=insertTree(root, 87);
  root=insertTree(root, 94);
  root=insertTree(root, 27);
  
  //printTree(root);
  
  printf("antes de remover \n");
  printTree(root);
  root=treeRemove(root,27);
  printf("\nDepois de remover \n");
  printTree(root);

 // Node* busca= treeSearch(root,20);
	
  
  treeFree(root);
  //treeFree(busca);
}