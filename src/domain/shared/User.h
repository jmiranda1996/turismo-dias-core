#ifndef User_H
#define User_H

#include <iostream>
#include "UserInfo.h"
#include "Enums.h"

using namespace std;

namespace tdc::domain::shared {
    class User {
        protected:
            string documentId;
            string username;
            string emailAddress;
            string passwordHash;
            string passwordSalt;
            time_t createdDate;
            UserInfo* userInfo;
            UserType userType;
            UserStatus status;
        public:
            User();
            User(string _documentId, string _username, string _emailAddress, UserInfo* _userInfo = nullptr);
            
            string getDocumentId(); //{ return this.documentId; }
            string getUsername(); //{ return this.username; }
            string getEmailAddress(); //{ return this.emailAddress; }
            string getPasswordHash(); //{ return this.passwordHash; }
            string getPasswordSalt(); //{ return this.passwordSalt; }
            time_t getCreatedDate();// { return this.createdDate; }
            UserInfo* getUserInfo();
            UserStatus getStatus();// { return this.status; }
            
            void setDocumentId(string _documentId);
            void setUsername(string _username);
            void setEmailAddress(string _emailAddress);
            void setPasswordHash(string _passwordHash);
            void setPasswordSalt(string _passwordSalt);
            void setCreatedDate(time_t _createDate);
            void setUserInfo(UserInfo* _userInfo);
            void setStatus(UserStatus _status);
    };
};

#endif
