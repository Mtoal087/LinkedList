#include <iostream>
using namespace std;

 
template <typename T>
std::ostream& operator<< (std::ostream& out, const LinkedList<T>& list){
    out << "[ ";
    LLNode<T>* temp = list.m_head;
    while (temp != NULL) {
        if(temp -> m_next == NULL)
            break;
        else{
            out << temp -> m_data << ", ";
            temp = temp -> m_next;
        }
    }
    out << "]";
    return out;
}

template <typename T>
LinkedList<T>::~LinkedList(){
    LLNode<T>* tmp;
	tmp = m_head -> m_next;
	while(tmp != NULL){
		delete m_head;
		m_head = tmp;
		tmp = m_head -> m_next;
	}
	delete m_head;
}

template <typename T>
const LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs){
    clear();
	LLNode<T>* p = m_head;
	LLNode<T>* q = rhs.m_head;
	while(q -> m_next != NULL){
		insert(p, q -> m_data);
		p = p -> m_next;
		q = q -> m_next;
	}
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs){
    LLNode<T>* temp = new LLNode<T>;
    m_size = rhs.m_size;
    while(rhs.m_head -> m_next != NULL){
        m_head -> m_data = rhs.m_head -> m_data;
        m_head -> m_next;
    }
}

template <typename T>
void LinkedList<T>::clear(){
	LLNode<T>* tmp;
	tmp = m_head -> m_next;
	while(tmp != NULL){
		delete m_head;
		m_head = tmp;
		tmp = m_head -> m_next;
	}
    delete tmp;
	m_size = 0;
}

template <typename T>
int LinkedList<T>::size() const{
    return m_size;
}

template <typename T>
bool LinkedList<T>::isEmpty() const{
    if(m_head -> m_next == NULL)
        return true;
    else    
        return false;
}

template <typename T>
LLNode<T>* LinkedList<T>::getFirstPtr(){
    if(m_head -> m_next == NULL)
        return NULL;
    else
        return m_head -> m_data;
}

template <typename T>
void LinkedList<T>::insert(const T& x, LLNode<T>* pos){
    LLNode<T>* tmp = new LLNode<T>;
	tmp -> m_data = pos -> m_data;
	tmp -> m_next = pos -> m_next;
	pos -> m_data = x;
	pos -> m_next = tmp;
	m_size++;
}

template <typename T>
void LinkedList<T>::insert_front(const T& x){
    insert(x, m_head);
}

template <typename T>
void LinkedList<T>::insert_back(const T& x){
    
}
