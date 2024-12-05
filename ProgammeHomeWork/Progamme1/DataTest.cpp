#include"ProgameHomeWork2.cpp"
#include <iostream>
#include <string>
    int main()
{
        myAlist<Book> bookList;
        bookList.init(10);
        int choice;
        //先book出10本书
        Book book1("1", "book1", "author1", 10, "publisher1", 1);
        Book book2("2", "book2", "author2", 20, "publisher2", 2);
        Book book3("3", "book3", "author3", 30, "publisher3", 3);
        Book book4("4", "book4", "author4", 40, "publisher4", 4);
        Book book5("5", "book5", "author5", 50, "publisher5", 5);
        Book book6("6", "book6", "author6", 60, "publisher6", 6);
        Book book7("7", "book7", "author7", 70, "publisher7", 7);
        Book book8("8", "book8", "author8", 80, "publisher8", 8);
        Book book9("9", "book9", "author9", 90, "publisher9", 9);
        Book book10("10", "book10", "author10", 100, "publisher10", 10);

        bookList.append(book1);
        bookList.append(book2);
        bookList.append(book3);
        bookList.append(book4);
        bookList.append(book5);
        bookList.append(book6);
        bookList.append(book7);
        bookList.append(book8);
        bookList.append(book9);
        bookList.append(book10);
        do
        {
            cout << "1. 查找图书" << endl;
            cout << "2. 图书上架" << endl;
            cout << "3. 图书下架" << endl;
            cout << "4. 图书删除" << endl;
            cout << "5. 显示所有图书" << endl;
            cout << "6. 退出" << endl;
            cout << "选择操作: ";
            cin >> choice;

            if (choice == 1)
            {
                string isbn;
                cout << "输入ISBN号: ";
                cin >> isbn;
                Book book(isbn, "", "", 0, "", 0);
                bookList.find(book);
            }
            else if (choice == 2)
            {
                string isbn, title, author, publisher;
                double price;
                int edition;
                cout << "输入ISBN号: ";
                cin >> isbn;
                cout << "输入书名: ";
                cin >> title;
                cout << "输入作者: ";
                cin >> author;
                cout << "输入定价: ";
                cin >> price;
                cout << "输入出版发行单位: ";
                cin >> publisher;
                cout << "输入印次: ";
                cin >> edition;
                Book book(isbn, title, author, price, publisher, edition);
                bookList.append(book);
            }
            else if (choice == 3)
            {
                string isbn;
                cout << "输入ISBN号: ";
                cin >> isbn;
                Book book(isbn, "", "", 0, "", 0);
                for (int i = 0; i < bookList.length(); i++)
                {
                    if (bookList.position(i) == book)
                    {
                        bookList.remove(i);
                        break;
                    }
                }
            }
            else if (choice == 4)
            {
                string isbn;
                cout << "输入ISBN号: ";
                cin >> isbn;
                Book book(isbn, "", "", 0, "", 0);
                for (int i = 0; i < bookList.length(); i++)
                {
                    if (bookList.position(i) == book)
                    {
                        bookList.remove(i);
                        break;
                    }
                }
            }
            else if (choice == 5)
            {
                bookList.print();
            }
        } while (choice != 6);
        return 0;
}