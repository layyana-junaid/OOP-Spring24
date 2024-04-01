/*
 *Programmer: Layyana Junaid (23k0056)
 *Date: 1st April 2024
 *Description:designing the core components of a social media app similar to Instagram.
*/

#include <iostream>
#include <string>

class User {
protected:
    std::string username;
    std::string email;
    std::string password;

public:
    User(const std::string& username, const std::string& email, const std::string& password)
        : username(username), email(email), password(password) {}

    virtual ~User() {}

    virtual void login() const {
        std::cout << "Logging in as " << username << std::endl;
    }

    virtual void viewProfile() const {
        std::cout << "Viewing profile of " << username << std::endl;
    }

    virtual void logout() const {
        std::cout << "Logging out" << std::endl;
    }

    std::string getUsername() const { return username; }
    std::string getEmail() const { return email; }
};

class RegularUser : public User {
private:
    static const int MAX_POSTS = 5;
    std::string posts[MAX_POSTS];
    int numPosts;

public:
    RegularUser(const std::string& username, const std::string& email, const std::string& password)
        : User(username, email, password), numPosts(0) {}

    void addPost(const std::string& post) {
        if (numPosts < MAX_POSTS) {
            posts[numPosts++] = post;
            std::cout << "Post added successfully" << std::endl;
        } else {
            std::cout << "You have reached the maximum number of posts" << std::endl;
        }
    }

    void viewFeed() const {
        std::cout << "Feed for user " << username << ":" << std::endl;
        for (int i = 0; i < numPosts; i++) {
            std::cout << posts[i] << std::endl;
        }
    }
};

class BusinessUser : public User {
private:
    static const int MAX_PROMOTED_POSTS = 10;
    int promotedPostsCount;

public:
    BusinessUser(const std::string& username, const std::string& email, const std::string& password)
        : User(username, email, password), promotedPostsCount(0) {}

    void promotePost(const std::string& post) {
    if (promotedPostsCount < MAX_PROMOTED_POSTS) {
        std::cout << "Post promoted successfully" << std::endl;
        promotedPostsCount++;
    } else {
        std::cout << "You have reached the maximum number of promoted posts" << std::endl;
    }
}


    void login() const override {
        std::cout << "Logging in as Business User " << username << std::endl;
    }
};

class Post {
private:
    int postId;
    std::string content;
    int likes;
    std::string comments[10];
    int numComments;

public:
    Post(int postId, const std::string& content)
        : postId(postId), content(content), likes(0), numComments(0) {}

    void addComment(const std::string& comment) {
        if (numComments < 10) {
            comments[numComments++] = comment;
        }
    }

    void like() {
        likes++;
    }

    void display() const {
        std::cout << "Post ID: " << postId << std::endl;
        std::cout << "Content: " << content << std::endl;
        std::cout << "Likes: " << likes << std::endl;
        std::cout << "Comments:" << std::endl;
        for (int i = 0; i < numComments; i++) {
            std::cout << "- " << comments[i] << std::endl;
        }
    }
};

int main() {


    std::cout << "Layyana Junaid [23k0056]" << std::endl;
    RegularUser regularUser1("Layyana Junaid", "nu@gmail.com", "password");
    RegularUser regularUser2("Harry Potter", "harry@gmail.com", "password");
    BusinessUser businessUser("AmyCorp", "amy@gmail.com", "password");

    regularUser1.addPost("A Day In My Life");
    regularUser1.addPost("post of the day");
    regularUser1.viewFeed();


    regularUser2.addPost("Sunday!");
    regularUser2.addPost("felt like posting>>");
    regularUser2.viewFeed();

    businessUser.promotePost("Check out our new product!");

    Post post(1, "Sample post");
    post.addComment("Amazing<3");
    post.like();
    post.display();

    return 0;
}
