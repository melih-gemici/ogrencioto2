#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    int numara;
    Node* next;
    Node* prev;

    Node(string name, int numara) {
        this->name = name;
        this->numara = numara;
        next = nullptr;
        prev = nullptr;
    }
};

class yonetimbilisimsistemlerilist { //sinif listesi olucak linklist olusturma
private:
    Node* head;
    Node* tail;
    int count;
    int countybs;
public:
    yonetimbilisimsistemlerilist() {
        head = nullptr;
        tail = nullptr;
        countybs=100;
        count = 100; 
    }

    void add(string name, int numara) { //ekleme
        numara=count;
        count++;
        Node* node = new Node(name, numara);
        if (head == nullptr) {
            head = node;
            tail = node;
            cout<<"ogrenci eklendi"<<endl;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;

            cout<<"ogrenci eklendi"<<endl;
        }
        ;
    }
     bool searchContact(string name) { // ayni isim var ise onu kontrol etmek icin yazildi maine true veya false gonderecek
        Node* tmp = head;
        while (tmp != nullptr) {
            if (tmp->name == name) {
                cout<<"ogrencinin kaydi gerceklesmistir"<<endl;
                return false;
                
            }
            tmp = tmp->next;
        }
        return true;
    } 
    void deleteContact(int numara) {//silme
        if (head == nullptr) {
            cout << "ogrenci bulunamadi" << endl;
            return;
        }

        if (head->numara == numara) { // Ilk eleman siliniyorsa
            Node* temp = head;
            head = head->next;
            if (head) head->prev = nullptr;
            delete temp;
            
            cout << "ogrenci silindi: " << numara << endl;
            return;
        }

        Node* tmp = head;
        while (tmp != nullptr && tmp->numara != numara) {
            tmp = tmp->next;
        }

        if (tmp == nullptr) {
            cout << "ogrenci bulunamadi: " << numara << endl;
        } else {
            if (tmp->prev) tmp->prev->next = tmp->next;
            if (tmp->next) tmp->next->prev = tmp->prev;
            delete tmp;
           
            cout << "ogrenci silindi: " << numara << endl;
        }
    }
     bool searchContacts(string name) { // ogrenci aramak 
        Node* tmp = head;
        while (tmp != nullptr) {
            if (tmp->name == name) {
                cout<<"yonetim bilisim sistemleri  "<< "- "<<"("<<name<<")"<<endl;
                return true;
                
            }
            tmp = tmp->next;
        } cout<<"ogrenci bulunmamaktadir"<<endl;
        return false;
    }  int countYbsStudents() {// sinif mevcudu sayaci
    Node* tmp = head; 
    int studentCount = 0; 

    while (tmp != nullptr) {
        studentCount++;  
        tmp = tmp->next; 
    }
      cout<<"sinif mevcudu : "<<studentCount<<endl;
    return studentCount; 
}    
    bool sinirYbsStudents() {// sinif mevcudunu sayar ve mevcut 5 i gecerse maine false gonderecek ve ogrenci eklenmeyecektir
    Node* tmp = head; 
    int studentCount = 0; 

    while (tmp != nullptr) {
        studentCount++;  
        tmp = tmp->next; 
    }
     if(studentCount<5){
        return true;
     }
     else{
        cout<<"sinif mevcudu full "<<endl;
        return false;
     }
}
   

     void printlistybs() {//sinif listeleme
        int ybsmevcut;
        ybsmevcut=count-countybs;
        if (head == nullptr) {
            cout << "yonetim bilisim sistemleri bolumunde öğrenci bulunamadı." << endl;
            return;
        }

        cout << " yonetim bilisim sistemleri Öğrenci listesi: " << endl;
        Node* tmp = head;
        while (tmp != nullptr) {
            cout << tmp->name<<tmp->numara << endl;
            tmp = tmp->next;

        } 
      
    }
   
};
class isletmelist {
private:
    Node* head;
    Node* tail;
    int counti;
    int count;
public:
    isletmelist() {
        head = nullptr;
        tail = nullptr;
        counti = 200; 
        count = 200;
    }

    void add(string name, int numara) {
        numara=count;
        count++;
        Node* node = new Node(name, numara);
        if (head == nullptr) {
            head = node;
            tail = node;
            cout<<"ogrenci eklendi"<<endl;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
            cout<<"ogrenci eklendi"<<endl;
        }
        
    }
     bool searchContact(string name) {
        Node* tmp = head;
        while (tmp != nullptr) {
            if (tmp->name == name) {
                cout<<"ogrencinin kaydi gerceklesmistir"<<endl;
                return false;
                
            }
            tmp = tmp->next;
        }
        return true;
    } 
     void deleteContact(int numara) {
        if (head == nullptr) {
            cout << "ogrenci bulunamadi" << endl;
            return;
        }

        if (head->numara == numara) { // Ilk eleman siliniyorsa
            Node* temp = head;
            head = head->next;
            if (head) head->prev = nullptr;
            delete temp;
            
            cout << "ogrenci silindi: " << numara << endl;
            return;
        }

        Node* tmp = head;
        while (tmp != nullptr && tmp->numara != numara) {
            tmp = tmp->next;
        }

        if (tmp == nullptr) {
            cout << "ogrenci bulunamadi: " << numara << endl;
        } else {
            if (tmp->prev) tmp->prev->next = tmp->next;
            if (tmp->next) tmp->next->prev = tmp->prev;
            delete tmp;
            
            cout << "ogrenci silindi: " << numara << endl;
        }
    }
     bool searchContacts(string name) {
        Node* tmp = head;
        while (tmp != nullptr) {
            if (tmp->name == name) {
                cout<<"isletme  "<< "- "<<"("<<name<<")"<<endl;
                return true;

            }
            tmp = tmp->next;
        }
        cout<<"ogrenci bulunmamaktadir"<<endl;
        return false;
    } 
    int countYbsStudents() {
    Node* tmp = head; 
    int studentCount = 0; 

    while (tmp != nullptr) {
        studentCount++;  
        tmp = tmp->next; 
    }
      cout<<"sinif mevcudu : "<<studentCount<<endl;
    return studentCount; 
}
bool sinirYbsStudents() {
    Node* tmp = head; 
    int studentCount = 0; 

    while (tmp != nullptr) {
        studentCount++;  
        tmp = tmp->next; 
    }
     if(studentCount<5){
        return true;
     }
     else{
        cout<<"sinif mevcudu full "<<endl;
        return false;
     }
}
     void printlistybs() {
        if (head == nullptr) {
            cout << "isletme bolumunde öğrenci bulunamadı." << endl;
            return;
        }

        cout << " isletme Öğrenci listesi: " << endl;
        Node* tmp = head;
        while (tmp != nullptr) {
            cout << tmp->name<<tmp->numara << endl;
            tmp = tmp->next;
        }
    }
};
class hemsirelist {
private:
    Node* head;
    Node* tail;
    int counth;
    int countybs;
public:
    hemsirelist() {
        head = nullptr;
        tail = nullptr;
        counth = 300; 
         int countybs=300;
    }

    void add(string name, int numara) {
        numara=counth;
        counth++;
        Node* node = new Node(name, numara);
        if (head == nullptr) {
            head = node;
            tail = node;
            cout<<"ogrenci eklendi"<<endl;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
            cout<<"ogrenci eklendi"<<endl;
        }
        
    }
     bool searchContact(string name) {
        Node* tmp = head;
        while (tmp != nullptr) {
            if (tmp->name == name) {
                cout<<"ogrencinin kaydi gerceklesmistir"<<endl;
                return false;
                
            }
            tmp = tmp->next;
        }
        return true;
    } 
    void deleteContact(int numara) {
        if (head == nullptr) {
            cout << "ogrenci bulunamadi" << endl;
            return;
        }

        if (head->numara == numara) { // Ilk eleman siliniyorsa
            Node* temp = head;
            head = head->next;
            if (head) head->prev = nullptr;
            delete temp;
            
            cout << "ogrenci silindi: " << numara << endl;
            return;
        }

        Node* tmp = head;
        while (tmp != nullptr && tmp->numara != numara) {
            tmp = tmp->next;
        }

        if (tmp == nullptr) {
            cout << "ogrenci bulunamadi: " << numara << endl;
        } else {
            if (tmp->prev) tmp->prev->next = tmp->next;
            if (tmp->next) tmp->next->prev = tmp->prev;
            delete tmp;
            
            cout << "ogrenci silindi: " << numara << endl;
        }
    }
     bool searchContacts(string name) {
        Node* tmp = head;
        while (tmp != nullptr) {
            if (tmp->name == name) {
                 cout<<"hemsirelik "<< "- "<<"("<<name<<")"<<endl;
                return true;
               
            }
            tmp = tmp->next;
        }
        cout<<"ogrenci bulunmamaktadir"<<endl;
        return false;
    } 
     int countYbsStudents() {
    Node* tmp = head; 
    int studentCount = 0; 

    while (tmp != nullptr) {
        studentCount++;  
        tmp = tmp->next; 
    }
      cout<<"sinif mevcudu : "<<studentCount<<endl;
    return studentCount; 
}
bool sinirYbsStudents() {
    Node* tmp = head; 
    int studentCount = 0; 

    while (tmp != nullptr) {
        studentCount++;  
        tmp = tmp->next; 
    }
     if(studentCount<5){
        return true;
     }
     else{
        cout<<"sinif mevcudu full "<<endl;
        return false;
     }
}
     void printlistybs() {
        if (head == nullptr) {
            cout << "hemsirelik bolumunde öğrenci bulunamadı." << endl;
            return;
        }

        cout << " hemsirelik Öğrenci listesi: " << endl;
        Node* tmp = head;
        while (tmp != nullptr) {
            cout << tmp->name<<tmp->numara << endl;
            tmp = tmp->next;
        }
    }
};
class lojistiklist {
private:
    Node* head;
    Node* tail;
    int countl;
    int countybs;
public:
    lojistiklist() {
        head = nullptr;
        tail = nullptr;
        countl =400 ; 
    }

    void add(string name, int numara) {
        countl=numara;
        countl ++;
        Node* node = new Node(name, numara);
        if (head == nullptr) {
            head = node;
            tail = node;
            cout<<"ogrenci eklendi"<<endl;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
            cout<<"ogrenci eklendi"<<endl;
        }
        
    }
     bool searchContact(string name) {
        Node* tmp = head;
        while (tmp != nullptr) {
            if (tmp->name == name) {
                cout<<"ogrencinin kaydi gerceklesmistir"<<endl;
                return false;
                
            }
            tmp = tmp->next;
        }
        return true;
    } 
    void deleteContact(int numara) {
        if (head == nullptr) {
            cout << "ogrenci bulunamadi" << endl;
            return;
        }

        if (head->numara == numara) { // Ilk eleman siliniyorsa
            Node* temp = head;
            head = head->next;
            if (head) head->prev = nullptr;
            delete temp;
            
            cout << "ogrenci silindi: " << numara << endl;
            return;
        }

        Node* tmp = head;
        while (tmp != nullptr && tmp->numara != numara) {
            tmp = tmp->next;
        }

        if (tmp == nullptr) {
            cout << "ogrenci bulunamadi: " << numara << endl;
        } else {
            if (tmp->prev) tmp->prev->next = tmp->next;
            if (tmp->next) tmp->next->prev = tmp->prev;
            delete tmp;
            
            cout << "ogrenci silindi: " << numara << endl;
        }
    }
     bool searchContacts(string name) {
        Node* tmp = head;
        while (tmp != nullptr) {
            if (tmp->name == name) {
                cout<<"lojistik "<< "- "<<"("<<name<<")"<<endl;
                return true;
                
            }
            tmp = tmp->next;
        }
        cout<<"ogrenci bulunmamaktadir"<<endl;
        return false;
    } 
      int countYbsStudents() {
    Node* tmp = head; 
    int studentCount = 0; 

    while (tmp != nullptr) {
        studentCount++;  
        tmp = tmp->next; 
    }
      cout<<"sinif mevcudu : "<<studentCount<<endl;
    return studentCount; 
}
bool sinirYbsStudents() {
    Node* tmp = head; 
    int studentCount = 0; 

    while (tmp != nullptr) {
        studentCount++;  
        tmp = tmp->next; 
    }
     if(studentCount<5){
        return true;
     }
     else{
        cout<<"sinif mevcudu full "<<endl;
        return false;
     }
}
     void printlistybs() {
        if (head == nullptr) {
            cout << "lojistik bolumunde öğrenci bulunamadı." << endl;
            return;
        }

        cout << " lojistik Öğrenci listesi: " << endl;
        Node* tmp = head;
        while (tmp != nullptr) {
            cout << tmp->name<<tmp->numara << endl;
            tmp = tmp->next;
        }
    }
};
class cocukgelisimilist {
private:
    Node* head;
    Node* tail;
    int countc;
    int countybs;
public:
    cocukgelisimilist() {
        head = nullptr;
        tail = nullptr;
        countc = 500; 
    }

    void add(string name, int numara) {
        numara=countc;
        countc ++;
        Node* node = new Node(name, numara);
        if (head == nullptr) {
            head = node;
            tail = node;
            cout<<"ogrenci eklendi"<<endl;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
            cout<<"ogrenci eklendi"<<endl;
        }
    }
     bool searchContact(string name) {
        Node* tmp = head;
        while (tmp != nullptr) {
            if (tmp->name == name) {
                cout<<"ogrencinin kaydi gerceklesmistir"<<endl;
                return false;
                
            }
            tmp = tmp->next;
        }
        return true;
    } 
    void deleteContact(int numara) {
        if (head == nullptr) {
            cout << "ogrenci bulunamadi" << endl;
            return;
        }

        if (head->numara == numara) { // Ilk eleman siliniyorsa
            Node* temp = head;
            head = head->next;
            if (head) head->prev = nullptr;
            delete temp;
            
            cout << "ogrenci silindi: " << numara << endl;
            return;
        }

        Node* tmp = head;
        while (tmp != nullptr && tmp->numara != numara) {
            tmp = tmp->next;
        }

        if (tmp == nullptr) {
            cout << "ogrenci bulunamadi: " << numara << endl;
        } else {
            if (tmp->prev) tmp->prev->next = tmp->next;
            if (tmp->next) tmp->next->prev = tmp->prev;
            delete tmp;
            
            cout << "ogrenci silindi: " << numara << endl;
            }
        }
    
     bool searchContacts(string name) {
        Node* tmp = head;
        while (tmp != nullptr) {
            if (tmp->name == name) {
                return true;
                cout<<"cocuk gelisimi  "<< "- "<<"("<<name<<")"<<endl;
            }
            tmp = tmp->next;
        }cout<<"ogrenci bulunmamaktadir"<<endl;
        return false;
    } 
      int countYbsStudents() {
    Node* tmp = head; 
    int studentCount = 0; 

    while (tmp != nullptr) {
        studentCount++;  
        tmp = tmp->next; 
    }
      cout<<"sinif mevcudu : "<<studentCount<<endl;
    return studentCount; 
}
bool sinirYbsStudents() {
    Node* tmp = head; 
    int studentCount = 0; 

    while (tmp != nullptr) {
        studentCount++;  
        tmp = tmp->next; 
    }
     if(studentCount<5){
        return true;
     }
     else{
        cout<<"sinif mevcudu full "<<endl;
        return false;
     }
}
     void printlistybs() {
        if (head == nullptr) {
            cout << "cocuk gelisimi bolumunde öğrenci bulunamadı." << endl;
            return;
        }

        cout << " cocuk gelisimi Öğrenci listesi: " << endl;
        Node* tmp = head;
        while (tmp != nullptr) {
            cout << tmp->name<<tmp->numara << endl;
            tmp = tmp->next;
        }
    }
};
int main(){
    
    string name;
    int numara;
    int choice;

    string ybs="ybs";
    string isletme="isletme";
    string hemsirelik="hemsirelik";
    string lojistik="lojistik";
    string cocukgelisimi="cocukgelisimi";
    string bolum;
    string evet="evet";
    string ucret;
    
    yonetimbilisimsistemlerilist Yonetimbilisimsistemlerilist ;//yeni isimlendirme linklistleri olusturma 
    isletmelist Isletmelist;
    hemsirelist Hemsirelist;
    lojistiklist Lojistiklist ;
    cocukgelisimilist Cocukgelisimilist;
     do {
        cout << "\n1. ogrenci Ekleme\n2. ogrenci Silme\n3. ogrenci Arama\n4. sinif Listeleme\n5.cikis\nseciminiz : ";
        cin >> choice;
        cin.ignore(); // Yeni satır karakterini temizlemek için

        switch (choice) {
            case 1:
                cout << "ogrenci adi : ";
                getline(cin, name);
                 cout<<"bolumu"<<endl;
                cin>>bolum;
                 if (bolum != ybs && bolum != isletme && bolum != lojistik && bolum != hemsirelik && bolum != cocukgelisimi) {
        cout << "Bu bolum bulunmamaktadir!" << endl;
        break;
    }
                if(bolum== ybs){
                    if(Yonetimbilisimsistemlerilist.sinirYbsStudents()){
                   if( Yonetimbilisimsistemlerilist.searchContact(name)){
                       cout<<"ogrenci kayit ucreti 100.000 tl eger ucret odendiyse evet yazin"<<endl;
                       cin>>ucret;
                       if (ucret==evet){ 
                          
                          
                          Yonetimbilisimsistemlerilist.add(name,numara);
                          }
                   }else{
                    break;
                   }
                }else{
                    break;}}
                if(bolum== isletme){
                    if(Isletmelist.sinirYbsStudents()){
                    if( Isletmelist.searchContact(name)){
                       cout<<"ogrenci kayit ucreti 110.000 tl eger ucret odendiyse evet yazin"<<endl;
                       cin>>ucret;
                       if (ucret==evet){ 
                          
                          Isletmelist.add(name,numara);
                          }
                   }else{
                    break;}}
                    else{
                        break;}
                   }
                if(bolum== lojistik){
                      if(Lojistiklist.sinirYbsStudents()){
                      if( Lojistiklist.searchContact(name)){
                       cout<<"ogrenci kayit ucreti 120.000 tl eger ucret odendiyse evet yazin"<<endl;
                       cin>>ucret;
                       if (ucret==evet){ 
                          
                          Lojistiklist.add(name,numara);
                          ;}
                   }else{
                    break;}}
                    else{
                        break;
                    }
                }
                if(bolum== hemsirelik){
                      if(Hemsirelist.sinirYbsStudents()){
                      if( Hemsirelist.searchContact(name)){
                       cout<<"ogrenci kayit ucreti 130.000 tl eger ucret odendiyse evet yazin"<<endl;
                       cin>>ucret;
                       if (ucret==evet){ 
                          
                          Hemsirelist.add(name,numara);
                          }
                    }else{
                    break;}}
                    else{
                        break;
                    }
                }
               
                if(bolum== cocukgelisimi){
                      if(Cocukgelisimilist.sinirYbsStudents()){
                      if(  Cocukgelisimilist.searchContact(name)){
                       cout<<"ogrenci kayit ucreti 140.000 tl eger ucret odendiyse evet yazin"<<endl;
                       cin>>ucret;
                       
                       if (ucret==evet){ 
                          
                          
                          
                         Cocukgelisimilist.add(name,numara);
                         }
                    }else{
                    break;}}
                    else{
                        break;
                    }
                }
                 
                
                break;
            case 2:
                cout<<"silmek istediginiz ogrencinin adi : "<<endl;
                cin>>name;
                cout << "Silmek istediginiz ogrencinin numarasi : ";
                cin>> numara;
                cout<<"bolumu"<<endl;
                cin>>bolum;
                 if (bolum != ybs && bolum != isletme && bolum != lojistik && bolum != hemsirelik && bolum != cocukgelisimi) {
        cout << "Bu bolum bulunmamaktadir!" << endl;
        break;
    }
                if (bolum== ybs) {
                    if(Yonetimbilisimsistemlerilist.searchContacts(name)){
                        Yonetimbilisimsistemlerilist.deleteContact(numara);
                    }else{
                        cout<<"ogrenci bulunmamaktadir"<<endl;
                        break;}
                }
                if (bolum== isletme) {
                    if(Isletmelist.searchContacts(name)){
                        Isletmelist.deleteContact(numara);
                    }else{
                        cout<<"ogrenci bulunmamaktadir"<<endl;
                        break;}
                }
                if (bolum== hemsirelik) {
                    if(Hemsirelist.searchContacts(name)){
                        Hemsirelist.deleteContact(numara);
                    }else{
                        cout<<"ogrenci bulunmamaktadir"<<endl;
                        break;}
                }
                if (bolum== lojistik) {
                    if(Lojistiklist.searchContacts(name)){
                        Lojistiklist.deleteContact(numara);
                    }else{
                        cout<<"ogrenci bulunmamaktadir"<<endl;
                        break;}
                }
                if (bolum== cocukgelisimi) {
                    if(Cocukgelisimilist.searchContacts(name))
                        Cocukgelisimilist.deleteContact(numara);
                    }else{
                        cout<<"ogrenci bulunmamaktadir"<<endl;
                        break;}
                
                
                break;
            case 3:
               
                cout << "Aramak istediginiz ogrencinin adi: "<<endl;
                getline(cin, name);
                cout<<"aramak istediginiz ogrencinin bolumu :  "<<endl;
                cin>>bolum;
                 if (bolum != ybs && bolum != isletme && bolum != lojistik && bolum != hemsirelik && bolum != cocukgelisimi) {
        cout << "Bu bolum bulunmamaktadir!" << endl;
        break;
    }
                if (bolum== ybs) {
                    Yonetimbilisimsistemlerilist.searchContacts(name);
                }
                if (bolum== isletme) {
                    Isletmelist.searchContacts(name);
                }
                if (bolum== hemsirelik) {
                    Hemsirelist.searchContacts(name);
                }
                if (bolum== lojistik) {
                    Lojistiklist.searchContacts(name);
                }
                if (bolum== cocukgelisimi) {
                    Cocukgelisimilist.searchContacts(name);
                }
                
                
                break;
            case 4:
                 cout<<"bolum : "<< endl;
                 cin>>bolum;
                  if (bolum != ybs && bolum != isletme && bolum != lojistik && bolum != hemsirelik && bolum != cocukgelisimi) {
        cout << "Bu bolum bulunmamaktadir!" << endl;
        break;
    }
                if (bolum== ybs) {
                Yonetimbilisimsistemlerilist.printlistybs();
                Yonetimbilisimsistemlerilist.countYbsStudents();
                    
                    
                }
                if (bolum== isletme) {
                    Isletmelist.printlistybs();
                    Isletmelist.countYbsStudents();
                }
                if (bolum== hemsirelik) {
                    Hemsirelist.printlistybs();
                    Hemsirelist.countYbsStudents();
                }
                if (bolum== lojistik) {
                    Lojistiklist.printlistybs();
                    Lojistiklist.countYbsStudents();
                }
                if (bolum== cocukgelisimi) {
                    Cocukgelisimilist.printlistybs();
                    Cocukgelisimilist.countYbsStudents();
                }
                
                
                break;
            
            
            case 5:
                cout<<"cikis yapiliyor"<<endl;    
            default:
                cout << "Gecersiz secim" << endl;  
                
        
    }} while (choice != 5);

    return 0;
 }