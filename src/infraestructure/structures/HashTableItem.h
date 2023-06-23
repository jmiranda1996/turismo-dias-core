#ifndef HashTableItem_H
#define HashTableItem_H

namespace tdc::infraestructure::structures {
    template <typename T>
    class HashTableItem {
        private:
            uint key;
            T* value;
        public:
            HashTableItem();
            HashTableItem(uint _key, T* _value = nullptr);

            uint getKey();
            T* getValue();

            void setKey(uint _key);
            void setValue(T* _value);
    };
}

#endif