**📋 Apa yang akan dipelajari**

Pada bab ini kita akan mempelajari tentang design patterns - solusi yang sudah terbukti untuk masalah umum dalam pemrograman:

- Pengenalan design patterns dan manfaatnya
- Singleton Pattern - Memastikan hanya ada satu instance
- Observer Pattern - Komunikasi antar objek
- MVC Pattern - Memisahkan logika dan tampilan
- Implementasi design patterns dalam Qt
- Relevansi signal-slot dengan Observer Pattern

\minitoc

## 🎨 Pengenalan Design Patterns

### Apa itu Design Pattern?

Design pattern adalah solusi yang sudah terbukti untuk masalah umum dalam pemrograman berorientasi objek. Pattern ini memberikan template yang bisa digunakan kembali untuk menyelesaikan masalah yang sering muncul.

> 
*"Design patterns adalah solusi yang sudah terbukti untuk masalah umum dalam software design."* - Gang of Four

### Manfaat Design Patterns

- **Reusability** - Solusi yang bisa digunakan kembali
- **Maintainability** - Kode yang mudah dipelihara
- **Communication** - Bahasa yang sama antar developer
- **Flexibility** - Kode yang fleksibel dan mudah diubah
- **Best Practices** - Mengikuti prinsip OOP yang baik

### Kategori Design Patterns

Design patterns dibagi menjadi tiga kategori utama:

- **Creational Patterns** - Cara membuat objek
- **Structural Patterns** - Cara menyusun objek
- **Behavioral Patterns** - Cara objek berkomunikasi

## 🏭 Singleton Pattern

### Pengenalan Singleton

Singleton pattern memastikan bahwa sebuah class hanya memiliki satu instance dan memberikan akses global ke instance tersebut.

### Kapan Menggunakan Singleton

- **Database connection** - Satu koneksi untuk seluruh aplikasi
- **Configuration manager** - Satu pengaturan untuk seluruh aplikasi
- **Logger** - Satu logger untuk seluruh aplikasi
- **Cache manager** - Satu cache untuk seluruh aplikasi

### Implementasi Singleton di C++

```cpp
#include <iostream>
using namespace std;

class Singleton {
private:
    static Singleton* instance;
    string data;
    
    // Constructor private
    Singleton() {
        data = "Singleton instance created";
    }
    
public:
    // Mencegah copy constructor
    Singleton(const Singleton&) = delete;
    
    // Mencegah assignment operator
    Singleton& operator=(const Singleton&) = delete;
    
    // Method untuk mendapatkan instance
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
    
    void setData(string value) {
        data = value;
    }
    
    string getData() {
        return data;
    }
    
    void showMessage() {
        cout << "Data: " << data << endl;
    }
};

// Inisialisasi static member
Singleton* Singleton::instance = nullptr;

int main() {
    // Mendapatkan instance
    Singleton* obj1 = Singleton::getInstance();
    obj1->setData("Hello from Singleton!");
    obj1->showMessage();
    
    // Mendapatkan instance yang sama
    Singleton* obj2 = Singleton::getInstance();
    obj2->showMessage(); // Akan menampilkan data yang sama
    
    cout << "obj1 == obj2: " << (obj1 == obj2) << endl; // true
    
    return 0;
}
```

### Singleton dalam Qt

Qt menggunakan Singleton pattern dalam beberapa komponen:

```cpp
#include <QApplication>
#include <QCoreApplication>

int main(int argc, char *argv[]) {
    // QApplication adalah singleton
    QApplication app(argc, argv);
    
    // QCoreApplication::instance() memberikan akses ke instance
    QCoreApplication* instance = QCoreApplication::instance();
    
    return app.exec();
}
```

## 👁️ Observer Pattern

### Pengenalan Observer

Observer pattern memungkinkan objek untuk berlangganan (subscribe) ke perubahan yang terjadi pada objek lain. Ketika objek yang diamati berubah, semua observer akan diberitahu.

### Komponen Observer Pattern

- **Subject** - Objek yang diamati
- **Observer** - Objek yang ingin diberitahu
- **Notify** - Method untuk memberitahu observer
- **Update** - Method yang dipanggil observer

### Implementasi Observer di C++

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Abstract Observer
class Observer {
public:
    virtual void update(string message) = 0;
};

// Concrete Observer
class NewsSubscriber : public Observer {
private:
    string name;
    
public:
    NewsSubscriber(string n) : name(n) {}
    
    void update(string message) override {
        cout << name << " received: " << message << endl;
    }
};

// Subject
class NewsAgency {
private:
    vector<Observer*> observers;
    string news;
    
public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }
    
    void detach(Observer* observer) {
        // Remove observer dari vector
        for (auto it = observers.begin(); it != observers.end(); ++it) {
            if (*it == observer) {
                observers.erase(it);
                break;
            }
        }
    }
    
    void notify() {
        for (Observer* observer : observers) {
            observer->update(news);
        }
    }
    
    void setNews(string n) {
        news = n;
        notify(); // Notify semua observer
    }
};

int main() {
    NewsAgency agency;
    
    NewsSubscriber* alice = new NewsSubscriber("Alice");
    NewsSubscriber* bob = new NewsSubscriber("Bob");
    NewsSubscriber* charlie = new NewsSubscriber("Charlie");
    
    // Attach observers
    agency.attach(alice);
    agency.attach(bob);
    agency.attach(charlie);
    
    // Set news - semua observer akan diberitahu
    agency.setNews("Breaking: C++ is awesome!");
    
    // Detach observer
    agency.detach(bob);
    
    // Set news lagi - hanya Alice dan Charlie yang diberitahu
    agency.setNews("Update: Qt is powerful!");
    
    return 0;
}
```

## 🔗 Signal-Slot sebagai Observer Pattern

### Relevansi Signal-Slot dengan Observer

Qt's signal-slot mechanism adalah implementasi dari Observer pattern. Signal berperan sebagai Subject, dan Slot berperan sebagai Observer.

### Implementasi Signal-Slot

```cpp
#include <QObject>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

class MyWidget : public QWidget {
    Q_OBJECT
    
private:
    QPushButton* button;
    QLabel* label;
    int counter = 0;
    
public:
    MyWidget(QWidget* parent = nullptr) : QWidget(parent) {
        // Setup UI
        QVBoxLayout* layout = new QVBoxLayout(this);
        
        button = new QPushButton("Click Me!", this);
        label = new QLabel("Counter: 0", this);
        
        layout->addWidget(button);
        layout->addWidget(label);
        
        // Connect signal to slot (Observer pattern)
        connect(button, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    }
    
private slots:
    void onButtonClicked() {
        counter++;
        label->setText("Counter: " + QString::number(counter));
    }
};
```

### Keunggulan Signal-Slot

- **Loose coupling** - Signal dan slot tidak saling mengenal
- **Type safety** - Compile-time checking
- **Automatic memory management** - Qt menangani cleanup
- **Thread safety** - Bisa digunakan di multi-threading

## 🏗️ MVC Pattern

### Pengenalan MVC

Model-View-Controller (MVC) adalah pattern yang memisahkan aplikasi menjadi tiga komponen:

- **Model** - Data dan business logic
- **View** - Tampilan user interface
- **Controller** - Menangani input dan mengupdate model/view

### Implementasi MVC Sederhana

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Model - Data dan business logic
class StudentModel {
private:
    vector<string> students;
    
public:
    void addStudent(string name) {
        students.push_back(name);
    }
    
    void removeStudent(string name) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (*it == name) {
                students.erase(it);
                break;
            }
        }
    }
    
    vector<string> getAllStudents() {
        return students;
    }
    
    int getStudentCount() {
        return students.size();
    }
};

// View - Tampilan
class StudentView {
public:
    void displayStudents(vector<string> students) {
        cout << "=== Daftar Mahasiswa ===" << endl;
        for (int i = 0; i < students.size(); i++) {
            cout << (i + 1) << ". " << students[i] << endl;
        }
        cout << "Total: " << students.size() << " mahasiswa" << endl;
        cout << "========================" << endl;
    }
    
    void displayMessage(string message) {
        cout << "Info: " << message << endl;
    }
};

// Controller - Menangani input dan mengupdate model/view
class StudentController {
private:
    StudentModel* model;
    StudentView* view;
    
public:
    StudentController(StudentModel* m, StudentView* v) : model(m), view(v) {}
    
    void addStudent(string name) {
        model->addStudent(name);
        view->displayMessage("Mahasiswa " + name + " ditambahkan");
        view->displayStudents(model->getAllStudents());
    }
    
    void removeStudent(string name) {
        model->removeStudent(name);
        view->displayMessage("Mahasiswa " + name + " dihapus");
        view->displayStudents(model->getAllStudents());
    }
    
    void showAllStudents() {
        view->displayStudents(model->getAllStudents());
    }
};

int main() {
    StudentModel model;
    StudentView view;
    StudentController controller(&model, &view);
    
    // Menambah mahasiswa
    controller.addStudent("Alice");
    controller.addStudent("Bob");
    controller.addStudent("Charlie");
    
    // Menghapus mahasiswa
    controller.removeStudent("Bob");
    
    return 0;
}
```

### MVC dalam Qt

Qt menggunakan konsep MVC dalam beberapa komponen:

```cpp
#include <QApplication>
#include <QListView>
#include <QStringListModel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>

class StudentManager : public QWidget {
    Q_OBJECT
    
private:
    QStringListModel* model;
    QListView* view;
    QPushButton* addButton;
    QPushButton* removeButton;
    
public:
    StudentManager(QWidget* parent = nullptr) : QWidget(parent) {
        // Model
        QStringList students;
        students << "Alice" << "Bob" << "Charlie";
        model = new QStringListModel(students, this);
        
        // View
        view = new QListView(this);
        view->setModel(model);
        
        // Controller (buttons)
        addButton = new QPushButton("Add Student", this);
        removeButton = new QPushButton("Remove Student", this);
        
        // Layout
        QVBoxLayout* layout = new QVBoxLayout(this);
        layout->addWidget(view);
        layout->addWidget(addButton);
        layout->addWidget(removeButton);
        
        // Connect signals to slots
        connect(addButton, SIGNAL(clicked()), this, SLOT(addStudent()));
        connect(removeButton, SIGNAL(clicked()), this, SLOT(removeStudent()));
    }
    
private slots:
    void addStudent() {
        QStringList list = model->stringList();
        list << "New Student";
        model->setStringList(list);
    }
    
    void removeStudent() {
        QModelIndex currentIndex = view->currentIndex();
        if (currentIndex.isValid()) {
            model->removeRow(currentIndex.row());
        }
    }
};
```

## 🎯 Best Practices Design Patterns

### Kapan Menggunakan Design Patterns

- **Gunakan ketika diperlukan** - Jangan over-engineer
- **Pahami masalah terlebih dahulu** - Pattern bukan solusi ajaib
- **Pertimbangkan kompleksitas** - Pattern bisa menambah kompleksitas
- **Dokumentasikan penggunaan** - Jelaskan mengapa pattern digunakan

### Anti-Patterns

- **God Object** - Satu class yang melakukan segalanya
- **Spaghetti Code** - Kode yang tidak terstruktur
- **Golden Hammer** - Menggunakan satu pattern untuk semua masalah
- **Over-Engineering** - Solusi yang terlalu kompleks

## 🔧 Implementasi Design Patterns dalam Qt

### Qt's Built-in Patterns

Qt sudah mengimplementasikan beberapa design patterns:

- **Signal-Slot** - Observer Pattern
- **QApplication** - Singleton Pattern
- **Model-View** - MVC Pattern
- **QObject** - Composite Pattern
- **QThread** - Strategy Pattern

### Contoh Implementasi Custom Pattern

```cpp
#include <QObject>
#include <QString>
#include <QList>

// Abstract Observer
class Observer : public QObject {
    Q_OBJECT
    
public:
    virtual void update(const QString& message) = 0;
};

// Subject
class Subject : public QObject {
    Q_OBJECT
    
private:
    QList<Observer*> observers;
    QString state;
    
public:
    void attach(Observer* observer) {
        observers.append(observer);
    }
    
    void detach(Observer* observer) {
        observers.removeOne(observer);
    }
    
    void setState(const QString& newState) {
        state = newState;
        notify();
    }
    
    QString getState() const {
        return state;
    }
    
private slots:
    void notify() {
        for (Observer* observer : observers) {
            observer->update(state);
        }
    }
};

// Concrete Observer
class ConcreteObserver : public Observer {
    Q_OBJECT
    
private:
    QString name;
    
public:
    ConcreteObserver(const QString& n) : name(n) {}
    
    void update(const QString& message) override {
        qDebug() << name << "received:" << message;
    }
};
```

## 📚 Referensi dan Bacaan Lanjutan

Untuk pemahaman yang lebih mendalam tentang design patterns, pembaca dapat merujuk pada:

- **Design Patterns: Elements of Reusable Object-Oriented Software** - Gang of Four[^1]: Gamma, E., Helm, R., Johnson, R., & Vlissides, J. (1994). "Design Patterns: Elements of Reusable Object-Oriented Software". Addison-Wesley.
- **Qt Design Patterns** - Dokumentasi Qt[^1]: Qt Company. (2023). "Qt Design Patterns". https://doc.qt.io/qt-6/design-patterns.html
- **Head First Design Patterns** - Freeman & Robson[^1]: Freeman, E., & Robson, E. (2004). "Head First Design Patterns". O'Reilly Media.
- **Modern C++ Design** - Alexandrescu[^1]: Alexandrescu, A. (2001). "Modern C++ Design: Generic Programming and Design Patterns Applied". Addison-Wesley.

## 🎉 Kesimpulan

Design patterns adalah alat yang powerful untuk membuat kode yang lebih baik, lebih maintainable, dan lebih reusable. Qt sudah mengimplementasikan banyak pattern yang bisa kita pelajari dan gunakan.

<div align="center">
**Design patterns membantu kita menulis kode yang lebih baik dan lebih mudah dipahami!** 🎨✨
</div>




<div align="center">
*--- Bab selanjutnya: Casting dan Database ---*
</div> 