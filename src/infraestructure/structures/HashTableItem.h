#ifndef HashTableItem_H
#define HashTableItem_H

namespace tdc::infraestructure::structures {
    template <typename T>
    class HashTableItem {
        private:
            int key;
            T* value;
        public:
            HashTableItem();
            HashTableItem(int _key, T* _value = nullptr);

            int getKey();
            T* getValue();

            void setKey(int _key);
            void setValue(T* _value);
    };
}

#endif