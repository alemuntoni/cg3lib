/**
    @author Stefano Nuvoli
*/
#include "bstnode.h"

namespace cg3 {

/* --------- CONSTRUCTORS/DESTRUCTOR --------- */


/**
 * @brief Constructor with key and value
 *
 * param[in] key Key of the node
 * param[in] value Value of the node
 */
template<class K, class T>
BSTNode<K,T>::BSTNode(
        const K& key,
        const T& value)
{
    init(key, new T(value));
}

/**
 * @brief Constructor with only key
 *
 * param[in] key Key of the node
 */
template<class K, class T>
BSTNode<K,T>::BSTNode(const K& key)
{
    init(key, nullptr);
}

/**
 * @brief Destructor
 */
template<class K, class T>
BSTNode<K,T>::~BSTNode()
{
    if (this->value != nullptr) {
        delete this->value;
        this->value = nullptr;
    }
}



/* --------- PUBLIC METHODS --------- */


/**
 * @brief Check if the node is a leaf
 *
 * @return True if the node is a leaf
 */
template<class K, class T>
inline bool BSTNode<K,T>::isLeaf() const {
    return (left == nullptr) && (right == nullptr);
}



/* --------- PRIVATE METHODS --------- */

/**
 * @brief Initialization of the node given key and value
 *
 * param[in] key Key of the node
 * param[in] value Value of the node
 */
template<class K, class T>
inline void BSTNode<K,T>::init(const K& key, T* value) {
    this->key = key;
    this->value = value;

    this->left = nullptr;
    this->right = nullptr;

    this->parent = nullptr;
}


}