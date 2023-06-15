namespace td::domian::shared {
    class User {
        private:
            int id;
        public:
            User() {
                id = 0;
            }
            int getId() {
                return id;
            }
    };
};