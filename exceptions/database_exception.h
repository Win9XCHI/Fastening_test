#ifndef DATABASE_EXCEPTION_H
#define DATABASE_EXCEPTION_H
#include <stdexcept>

class DatabaseException: public std::exception {
private:
    std::string m_error;

public:
    DatabaseException(std::string error) : m_error(error) {	}

    const char* what() const noexcept { return m_error.c_str(); }
};

#endif // DATABASE_EXCEPTION_H
