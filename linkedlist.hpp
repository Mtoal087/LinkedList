////////////////////////////////
//                            //
//         Matt Toal          //
//       Section: 103         //
//                            //
////////////////////////////////

#include <iostream>
using namespace std;

 
template <typename T>
std::ostream& operator<< (std::ostream& out, const LinkedList<T>& list){
    out << "[ ";
    LLNode<T>* temp = list.m_head;
    while (temp != NULL) {
        if(temp->m_next == NULL)
            break;
        else{
            out << temp->m_data << ", ";
            temp = temp->m_next;
        }
    }
    out << "]";
    return out;
}

template <typename T>
LinkedList<T>::~LinkedList(){
    LLNode<T>* tmp;
	tmp = m_head->m_next;
	while(tmp != NULL){
		delete m_head;
		m_head = tmp;
		tmp = m_head->m_next;
	}
	delete m_head;
}

template <typename T>
const LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs){
    clear();
    if (rhs.m_head == NULL)
        m_head = NULL;
    else{
        LLNode<T>* rhs_temp = rhs.m_head;
        for(int i = 0; i < rhs.m_size; i++){
            insert_back(rhs_temp->m_data);
            rhs_temp = rhs_temp->m_next;
        }
    }
    return *this;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs){
    if(rhs.m_head == NULL){
        m_head = NULL;
    } else {
        LLNode<T>* temp = new LLNode<T>;
        temp->m_data = rhs.m_head->m_data;
        temp->m_next = NULL;
        m_head = temp;

        LLNode<T>* temp0 = rhs.m_head->m_next;
        LLNode<T>* temp1 = m_head;
        while(temp0 != NULL){
            temp1->m_next = new LLNode<T>;
            temp1->m_next->m_data = temp0->m_data;
            temp1->m_next->m_next = NULL;
            temp1 = temp1->m_next;
            temp0 = temp0->m_next;
        }
    }
    m_size = rhs.m_size;
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
    if (m_size == 0)
        return NULL;
    else
        return m_head;
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
    if(m_head -> m_next == NULL)
        insert(x, m_head);
    else{
        LLNode<T>* tmp = new LLNode<T>;
        tmp = m_head -> m_next;
        while(tmp->m_next != NULL){
            tmp = tmp -> m_next;
        }
        insert(x, tmp);
    }
}

template <typename T>
LLNode<T>* LinkedList<T>::getAtPtr(int i){
    if(i >= 0 && i <= m_size){
        LLNode<T>* tmp = m_head;
        for (int j = 0; j < i; j++)
            tmp = tmp -> m_next;
        return tmp;
    }
    else
        return NULL;
}

template <typename T>
void LinkedList<T>::remove(LLNode<T>* pos){
    LLNode<T>* tmp = pos -> m_next;
	*pos = *tmp;
	delete tmp;
	m_size--;
}

template <typename T>
void LinkedList<T>::remove_front(){
    remove(m_head);
}

template <typename T>
void LinkedList<T>::remove_back(){
    if(m_head->m_next == NULL){
        m_head = NULL;
    } else{
        LLNode<T>* temp = m_head;
        while(temp->m_next->m_next != NULL){
            temp = temp->m_next;
        }
        LLNode<T>* lastNode = temp->m_next;
        temp->m_next = NULL;
        free(lastNode);
        m_size--;
    }
}

template <typename T>
LLNode<T>* LinkedList<T>::find(const T& x){
    LLNode<T>* temp = m_head;
    bool found = false;
    while(found == false && temp -> m_next != NULL){
        if(temp ->m_data == x)
            return temp;
        temp = temp ->m_next;
    }
    temp = NULL;
    return temp;
}

  // Purpose: determines whether this list is identical to rhs list in
  //      terms of data values and their order in the list
  // Parameters: rhs is list to be compared to this list
  // Returns: true if lists are identical; otherwise, false
template <typename T>
bool LinkedList<T>::operator== (const LinkedList<T>& rhs) const{
    if(m_size != rhs.m_size)
        return false;
    LLNode<T>* temp = m_head;
    LLNode<T>* rhs_temp = rhs.m_head;
    for(int i = 0; i < m_size; i++){
        if(temp->m_data != rhs_temp->m_data)
            return false;
        
        temp = temp -> m_next;
        rhs_temp = rhs_temp -> m_next;
    }
    return true;
}

template <typename T>
void LinkedList<T>::append(const LinkedList<T>& l2){
    LLNode<T>* temp = l2.m_head;
    for(int i = 0; i < l2.m_size; i++){
        insert_back(temp->m_data);
        temp = temp->m_next;
    }
}

template <typename T>
void LinkedList<T>::reverse(){
    if(m_head != NULL){
        LinkedList<T> tmplist;
        LLNode<T>* tmp = m_head;
        while (tmp -> m_next != NULL)
        {
            tmplist.insert_front(tmp->m_data);
            tmp = tmp -> m_next;
        }
        clear();
        *this = tmplist;
    }
}

  // Purpose: Removes duplicates from a Linked List.
  // Postconditions: all duplicate elements are removed from the list.
  //    the first occurance of an element is kept.
template <typename T>
void LinkedList<T>::purge(){
    LLNode<T>* tmp = m_head;
    while(tmp != NULL){
        LLNode<T>* compare = tmp->m_next;
        while(compare != NULL){
            if(tmp->m_data == compare->m_data){
                remove(compare);
            }
            compare = compare->m_next;
        }
        tmp = tmp->m_next;
    }
}

template <typename T>
void LinkedList<T>::slice(const LinkedList<T>& l2, LLNode<T>* start, LLNode<T>* stop){
    if(!l2.isEmpty()){
        clear();
        LLNode<T>* tmp = start;
        while (tmp -> m_next != stop -> m_next){
            insert_back(tmp -> m_data);
            tmp = tmp -> m_next;
        }
    }
}