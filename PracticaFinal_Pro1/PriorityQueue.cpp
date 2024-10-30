#include <iostream>
#include "PriorityQueue.hpp"

using namespace std;
//*********************************************************
// Constructors
//*********************************************************

template <typename T>
/* Pre: cert */
/* Post: el resultat és una cua amb prioritat sense cap element */
Queue<T>::Queue() {
	first = last = NULL;
	_size = 0;
}

template <typename T>
/* Pre: cert */
/* Post: el resultat és una cua amb prioritat còpia de la cua rebuda */
Queue<T>::Queue(Queue &q) {
	copyItems(q.first, first, last, _size);
}

//*********************************************************
// Destructor
//*********************************************************

template <typename T>
/* destructor per defecte */
Queue<T>::~Queue() {
	deleteItems(first);
	_size = 0;
}

//*********************************************************
// Modificadors
//*********************************************************

template <typename T>
/* Pre: cert */
/* Post: operació d'assignació de priorityques  */
Queue<T>& Queue<T>::operator=(const Queue &q) {
	if (this != &q) {
		deleteItems(first);
		copyItems(q.first, first, last, _size);
	}
	return *this;
}

template <typename T>
/* Pre: el paràmetre implícit no és buit */
/* Post: elimina el primer element del paràmetre implícit	*/
void Queue<T>::pop() {
	if (first == NULL) {
		cerr << "Error: pop on empty queue" << endl;
		exit(0);
	}
	Item *aux = first;
	first = first-> next;
	delete aux;
	_size--;
	if (first == NULL) last = NULL;
}

template <typename T>
/* Pre: cert */
/* Post: afegeix el valor rebut per paràmetre en el paràmetre implícit, tenint en compte la seva prioritat */
void Queue<T>::push(const T &value) {
	Item *pitem = new Item();
	pitem->value = value;
	_size++;
	if (first == NULL or value.compare(first->value)) {
		pitem->next = first;
		first = pitem;
		if (last == NULL) last = first;
		return;
	}
	Item *current = first;
	while (current->next != NULL and not (value.compare(current->next->value)))
		current = current->next;
	pitem->next = current->next;
	current->next = pitem;
	if (last == current) last = pitem;
}

//*********************************************************
template <typename T>
/* Pre: el paràmetre implícit no és buit */
/* Post: elimina el valor rebut per paràmetre del paràmetre implícit */
void Queue<T>::remove(const T &value)
{
	//la funció elimina el primer element que coincideixi amb el valor passat per paràmetre
	if (first == nullptr){ //CD 1: la cua no és buida 
		exit(0);
	}
	if (first -> value == value){ //CD 2: el primer valor ja és el que volem eliminar 
		Item *ptemp = first; 
		first = first -> next; 
		delete ptemp;
		--_size; 
	}
	Item *current = first; 
	// Inv: Després de cada iteració del bucle, la llista enllaçada fins a 'current' (incloent-ho) no conté cap element amb el valor 'value', 
	// i 'current' apunta al següent element de la llista o bé és nul si hem arribat al final de la llista.
	while (current -> next != nullptr){
		if (current -> next -> value == value){
			Item *ptemp = current -> next; 
			current -> next = current -> next -> next; 
			delete ptemp; 
			--_size; 
		}
		current = current -> next; 
	}
}
//*********************************************************


//*********************************************************
// Consultors
//*********************************************************

template <typename T>
/* Pre: el paràmetre implícit no és buit */
/* Post: el resultat és el primer element del paràmetre implícit */
T Queue<T>::front() const {
	if (first == NULL) {
	cerr << "Error: front on empty queue" << endl;
	exit(0);
	}
	return first->value;
}	

template <typename T>
/* Pre: cert */
/* Post: el resultat és el nombre d'elements del paràmetre implícit */  
int Queue<T>::size() const {
	return _size;
}

template <typename T>
/* Pre: cert */
/* Post: el resultat indica si el paràmetre implícit és buit o no */
bool Queue<T>::empty() const {
	return first == NULL;
}

//*********************************************************
// Lectura i escriptura
//*********************************************************
	
template<typename U>
/* Pre: cert */
/* Post: s'han escrit al canal estàndard de sortida els elements de q */
ostream &operator<<(ostream &os, Queue<U> &q){
  typename Queue<U>::Item *item;
  for (item = q.first; item != NULL; item = item->next) {
    os << "  " << item->value << endl;
  }
  if (q.last != NULL) {
		cout << "last no NULL" << endl;
		cout << "value: " << q.last->value << " " << "next: " << q.last->next << endl;
  }
  else {
	  cout << "last NUL" << endl;
	  cout << q.last << endl;
  }
  os << endl;
  return os;
}

template<typename U>
/* Pre: q està buida; el canal estàndard d'entrada els elements d'una cua Q */
/* Post: q = Q */
istream &operator>>(istream &is, Queue<U> &q) {
  int size;
  is >> size;
  if (size == 0) {
    q = Queue<U> ();
    return is;
  }
  for (int i = 0; i < size; ++i) {
    U x;
    cin >> x;
    q.push(x);
  }
  return is;
}

//*********************************************************
// Mètodes privats auxiliars
//*********************************************************

template <typename T>	
void Queue<T>::copyItems(const Item *item, Item *(&first), Item *(&last), int &_size) {
	if (item == NULL) {
		first = NULL;
		last = NULL;
		_size = 0;
		return;
	}
	first = new Item();
	first->value = item->value;
	last = first;
	_size = 1;
	while (item->next != NULL) {
		last->next = new Item();
		last = last->next;
		item = item->next;
		last->value = item->value;
		_size++;
	}
	last->next = NULL;
}

template <typename T>
void Queue<T>::deleteItems(Item *item) {
	while (item != NULL) {
		Item *aux = item;
		item = item->next;
		delete aux;
	}
}

