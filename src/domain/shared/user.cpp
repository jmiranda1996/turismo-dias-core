#include "User.h"
#include "UserInfo.h"
#include "Enums.h"

namespace tdc::domain::shared {
    User::User() {
        documentId = "";
        username = "";
        emailAddress = "";
        passwordHash = "";
        passwordSalt = "";
        createdDate = time(0);
        userInfo = nullptr;
        userType = Unknown;
        status = PendingConfirm;
    };
    User::User(string _documentId, string _username, string _emailAddress, UserInfo* _userInfo) {
        documentId = _documentId;
        username = _username;
        emailAddress = _emailAddress;
        passwordHash = "";
        passwordSalt = "";
        createdDate = time(0);
        userInfo = _userInfo;
        userType = Unknown;
        status = PendingConfirm;
    };

    string User::getDocumentId() { return documentId; }
    string User::getUsername() { return username; }
    string User::getEmailAddress() { return emailAddress; }
    string User::getPasswordHash() { return passwordHash; }
    string User::getPasswordSalt() { return passwordSalt; }
    time_t User::getCreatedDate() { return createdDate; }
    UserInfo* User::getUserInfo() { return userInfo; }
    UserStatus User::getStatus() { return status; }

    void User::setDocumentId(string _documentId) { documentId = _documentId; };
    void User::setUsername(string _username) { username = _username; };
    void User::setEmailAddress(string _emailAddress) { emailAddress = _emailAddress; };
    void User::setPasswordHash(string _passwordHash) { passwordHash = _passwordHash; };
    void User::setPasswordSalt(string _passwordSalt) { passwordSalt = _passwordSalt; };
    void User::setCreatedDate(time_t _createdDate) { createdDate = _createdDate; };
    void User::setUserInfo(UserInfo* _userInfo) { userInfo = _userInfo; };
    void User::setStatus(UserStatus _status) { status = _status; };
};