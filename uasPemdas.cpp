
/**
 *@mainpage Program Menghitung Nilai Matakuliah
 *@section  intro_sec  Pendahuluan
 * Program ini dibuat untuk memudahkan user dalam menghitung rerata nilai akhir matakuliah pemrograman dan jaringan
 * 
 * @section note_sec Struktur Program
 * - \b Matakuliah adalah sebagai base class utama
 * - \b Pemrograman adalah subclass yang merupakan turunan dari matakuliah
 * - \b Jaringan adalah subclass yang merupakan turunan dari matakuliah
 * 
 */


/**
 * @file uasPemdas.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
using namespace std;

/**
 * @class Matakuliah
 * @brief ini adalah base class utama yang digunakan untuk inheritance
 * 
 */

class MataKuliah
{
    private:
        float presensi,activity,exercise,tugasAkhir;

    public:

    /**
     * @brief konstruktor default course untuk set nilai awal
     * 
     */

        MataKuliah()
    {   
    presensi = 0.0;
    activity = 0.0;
    exercise = 0.0;
    tugasAkhir = 0.0;
    
    }
    virtual string namaMataKuliah() { return ""; }
    virtual void inputNilai(){}
    virtual float hitungNilaiAkhir(){return 0;}
    virtual void cekKelulusan(){}
    

    void setPresensi(float nilai){
        this->presensi = nilai;
    }
    float getPresensi(){
        return presensi;}

    void setActivity(float acti){
        this->activity = acti;
    }
    float getActivity(){
        return activity;
    }

    void setExercise(float ex){
        this->exercise = ex;
    }
    float getExercise(){
        return exercise;
    }

    void setTugasAkhir(float ta){
        this->tugasAkhir = ta;
    }
    float getTugasAkhir(){
        return tugasAkhir;
    }
    
};


/**
 * @class Pemrograman
 * @brief ini adalah kelas turunan dari kelas Matakuliah
 * 
 */

class Pemrograman : public MataKuliah
{
    public:
    string namaMataKuliah()
    {return "Pemrograman";}
    
    void inputNilai(){
        cout << "Masukan Nilai Presensi : ";
        float nilPres;
        cin >> nilPres;
        setPresensi(nilPres);

        cout << "Masukkan Nilai Activity : ";
        float nilAc;
        cin >> nilAc;
        setActivity(nilAc);

        cout << "Masukkan Nilai Exercise : ";
        float nilEx;
        cin >> nilEx;
        setExercise(nilEx);

        cout << "Masukan Nilai Tugas Akhir : ";
        float nilAkhir;
        cin >> nilAkhir;
        setTugasAkhir(nilAkhir);
    }

    float hitungNilaiAkhir() {
        return (getPresensi()*0.1) + (getActivity()*0.2) + (getExercise()*0.3) + (getTugasAkhir()*0.4);
    }

    void cekKelulusan(){
        float nilAkhir = hitungNilaiAkhir();
        if(nilAkhir >= 75){
            cout << "Selamat Anda Dinyatakan Lulus " << this->hitungNilaiAkhir() << endl;
        }else{
            cout << "Nilai Akhir : " << this-> hitungNilaiAkhir() << endl;
            cout << "Anda dinyatakan tidak lulus";
        }
    }
};

/**
 * @class Jaringan
 * @brief ini adalah kelas turunan dari kelas matakuliah
 * 
 */

class Jaringan : public MataKuliah
{
    public:
        string namaMataKuliah()
        {return "Jaringan";}

    void inputNilai(){
        cout << "Masukkan Nilai Activity : ";
        float nilAc;
        cin >> nilAc;
        setActivity(nilAc);

        cout << "Masukkan Nilai Exercise : ";
        float nilEx;
        cin >> nilEx;
        setExercise(nilEx);
    }

    float hitungNilaiAkhir(){
        return(getActivity()*0.6)+ (getExercise()*0.4);
    }

    void cekKelulusan(){
        float nilAkhir = hitungNilaiAkhir();
        if(nilAkhir >= 75){
            cout << "Nilai Akhir : " << this-> hitungNilaiAkhir() << endl;
            cout << "Selamat Anda Dinyatakan Lulus";
        }else{
            cout << "Nilai Akhir : " << this-> hitungNilaiAkhir() << endl;
            cout << "Anda dinyatakan tidak lulus";
        }
    }
};
int main()
{
    char pilih;
    MataKuliah *mataKuliah;
    Pemrograman pemrograman;
    Jaringan jaringan;
    
    cout << "Pilih Mata Kuliah :" << endl;
    cout << "1. Pemrograman " << endl;
    cout << "2. Jaringan "<< endl;
    cout << "3. Keluar" << endl;
    cout << "pilih : ";
    cin >> pilih;

    switch (pilih) {
        case '1':
            mataKuliah = &pemrograman;
            cout << "Matakuliah " << mataKuliah->namaMataKuliah() << endl;
            mataKuliah->inputNilai();
            mataKuliah->cekKelulusan();
            break;
        case '2':
            mataKuliah = &jaringan;
            cout << "Matakuliah " << mataKuliah->namaMataKuliah() << endl;
            mataKuliah->inputNilai();
            mataKuliah->cekKelulusan();
            break;
        case '3':
            cout << "Keluar dari program." << endl;
            return 0;
        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
    }
}