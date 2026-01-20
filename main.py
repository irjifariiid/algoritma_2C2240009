import csv
from datetime import datetime
from PIL import Image
import os

# Dictionary ramalan zodiak 2026
ramalan_zodiak = {
    "Aries": {
        "keuangan": "Tahun penuh kelimpahan; investasi masa lalu mulai membuahkan hasil besar.",
        "karir": "Peluang ekspansi bisnis atau proyek baru sangat terbuka lebar di pertengahan tahun.",
        "asmara": "Energi Jupiter membawa gairah baru bagi pasangan, sementara yang lajang berpeluang bertemu seseorang yang visioner.",
        "gambar": "images/aries.png"
    },
    "Taurus": {
        "keuangan": "Stabilitas meningkat. Fokus pada pengelolaan aset jangka panjang akan sangat menguntungkan.",
        "karir": "Perubahan mendadak di tempat kerja menuntut adaptasi, namun akan berujung pada posisi yang lebih baik.",
        "asmara": "Tahun untuk membangun komitmen yang lebih serius atau merencanakan pernikahan.",
        "gambar": "images/taurus.png"
    },
    "Gemini": {
        "keuangan": "Arus kas lancar, namun hindari pengeluaran impulsif untuk gaya hidup di akhir tahun.",
        "karir": "Kemampuan komunikasi menjadi kunci sukses dalam negosiasi besar.",
        "asmara": "Hubungan terasa lebih ringan dan menyenangkan; komunikasi yang jujur mempererat ikatan.",
        "gambar": "images/gemini.png"
    },
    "Cancer": {
        "keuangan": "Zodiak paling beruntung 2026. Peluang rezeki tak terduga datang dari berbagai arah.",
        "karir": "Peningkatan status sosial dan pengakuan profesional yang signifikan.",
        "asmara": "Waktu yang tepat untuk penyembuhan emosional dan memulai babak baru yang lebih stabil.",
        "gambar": "images/cancer.png"
    },
    "Leo": {
        "keuangan": "Perlu disiplin ketat di awal tahun agar tabungan tetap aman untuk investasi di akhir tahun.",
        "karir": "Karisma menarik perhatian atasan; peluang kepemimpinan sangat tinggi.",
        "asmara": "Fokus pada pengembangan diri akan membuat lebih menarik di mata pasangan atau calon pasangan.",
        "gambar": "images/leo.png"
    },
    "Virgo": {
        "keuangan": "Kondisi finansial stabil, namun hindari meminjamkan uang dalam jumlah besar kepada teman.",
        "karir": "Kerja keras akhirnya diakui dengan kenaikan jabatan atau bonus performa.",
        "asmara": "Sedikit tantangan dalam komunikasi; penting untuk tidak terlalu kritis terhadap pasangan.",
        "gambar": "images/virgo.png"
    },
    "Libra": {
        "keuangan": "Kemitraan bisnis akan mendatangkan keuntungan finansial yang solid.",
        "karir": "Jaringan sosial (networking) akan membuka pintu ke jenjang karir yang lebih bergengsi.",
        "asmara": "Harmonisasi hubungan menjadi fokus utama; tahun yang romantis bagi yang sudah berpasangan.",
        "gambar": "images/libra.png"
    },
    "Scorpio": {
        "keuangan": "Transformasi cara mengelola uang; ada peluang dari sumber pendapatan pasif.",
        "karir": "Fokus pada detail akan menyelamatkan dari kesalahan besar di tempat kerja.",
        "asmara": "Intensitas emosional tinggi; pastikan untuk memberikan ruang privasi bagi satu sama lain.",
        "gambar": "images/scorpio.png"
    },
    "Sagittarius": {
        "keuangan": "Keberuntungan datang melalui perjalanan atau bisnis yang berkaitan dengan luar daerah/negeri.",
        "karir": "Tahun yang tepat untuk mempelajari keahlian baru atau mengambil kursus sertifikasi.",
        "asmara": "Kebebasan dan petualangan menjadi tema utama dalam hubungan tahun ini.",
        "gambar": "images/sagittarius.png"
    },
    "Capricorn": {
        "keuangan": "Pertumbuhan aset properti atau tanah diprediksi sangat positif.",
        "karir": "Kerja keras dan kedisiplinan membawa pada pencapaian tertinggi dalam 5 tahun terakhir.",
        "asmara": "Peluang besar bagi yang lajang untuk menemukan pasangan yang memiliki visi hidup yang sama.",
        "gambar": "images/capricorn.png"
    },
    "Aquarius": {
        "keuangan": "Inovasi dalam cara mencari uang (seperti teknologi atau digital) akan sangat menguntungkan.",
        "karir": "Menjadi pusat perhatian di lingkungan kerja karena ide-ide kreatif yang orisinal.",
        "asmara": "Hubungan yang dimulai dari pertemanan memiliki peluang besar untuk berlanjut ke tahap serius.",
        "gambar": "images/aquarius.png"
    },
    "Pisces": {
        "keuangan": "Intuisi kuat dalam memilih investasi; namun tetap gunakan logika dalam transaksi besar.",
        "karir": "Kreativitas dan empati membuat unggul dalam pekerjaan yang berhubungan dengan pelayanan.",
        "asmara": "Tahun yang penuh empati dan pengertian; hubungan akan terasa lebih spiritual dan mendalam.",
        "gambar": "images/pisces.png"
    }
}

# List untuk menyimpan riwayat
riwayat_ramalan = []

def tentukan_zodiak(tanggal, bulan):
    """Menentukan zodiak berdasarkan tanggal dan bulan lahir"""
    if (bulan == 3 and tanggal >= 21) or (bulan == 4 and tanggal <= 19):
        return "Aries"
    elif (bulan == 4 and tanggal >= 20) or (bulan == 5 and tanggal <= 20):
        return "Taurus"
    elif (bulan == 5 and tanggal >= 21) or (bulan == 6 and tanggal <= 20):
        return "Gemini"
    elif (bulan == 6 and tanggal >= 21) or (bulan == 7 and tanggal <= 22):
        return "Cancer"
    elif (bulan == 7 and tanggal >= 23) or (bulan == 8 and tanggal <= 22):
        return "Leo"
    elif (bulan == 8 and tanggal >= 23) or (bulan == 9 and tanggal <= 22):
        return "Virgo"
    elif (bulan == 9 and tanggal >= 23) or (bulan == 10 and tanggal <= 22):
        return "Libra"
    elif (bulan == 10 and tanggal >= 23) or (bulan == 11 and tanggal <= 21):
        return "Scorpio"
    elif (bulan == 11 and tanggal >= 22) or (bulan == 12 and tanggal <= 21):
        return "Sagittarius"
    elif (bulan == 12 and tanggal >= 22) or (bulan == 1 and tanggal <= 19):
        return "Capricorn"
    elif (bulan == 1 and tanggal >= 20) or (bulan == 2 and tanggal <= 18):
        return "Aquarius"
    elif (bulan == 2 and tanggal >= 19) or (bulan == 3 and tanggal <= 20):
        return "Pisces"
    else:
        return None

def tampilkan_gambar(path_gambar):
    """Menampilkan gambar zodiak"""
    try:
        if os.path.exists(path_gambar):
            img = Image.open(path_gambar)
            img.show()
            return True
        else:
            print(f"\n⚠️  Gambar tidak ditemukan: {path_gambar}")
            print("   Pastikan folder 'images' berisi file gambar zodiak (aries.png, taurus.png, dst.)")
            return False
    except Exception as e:
        print(f"\n⚠️  Error saat membuka gambar: {e}")
        return False

def tampilkan_logo_zodiak():
    """Menampilkan logo/banner zodiak di menu utama"""
    logo_path = "images/zodiak_logo.png"
    try:
        if os.path.exists(logo_path):
            print("\n🖼️  Menampilkan logo aplikasi...")
            img = Image.open(logo_path)
            img.show()
        else:
            print("\n💡 Tip: Letakkan file 'zodiac_logo.png' di folder 'images' untuk menampilkan logo aplikasi")
    except Exception as e:
        pass  # Tidak menampilkan error jika logo tidak ada

def tampilkan_ramalan():
    """Menu 1: Menampilkan ramalan zodiak"""
    print("\n" + "="*70)
    print("              🌟 CEK RAMALAN ZODIAK 2026 🌟")
    print("="*70)
    
    try:
        tanggal = int(input("Masukkan tanggal lahir (1-31): "))
        bulan = int(input("Masukkan bulan lahir (1-12): "))
        
        if tanggal < 1 or tanggal > 31 or bulan < 1 or bulan > 12:
            print("\n❌ Tanggal atau bulan tidak valid!")
            return
        
        zodiak = tentukan_zodiak(tanggal, bulan)
        
        if zodiak:
            data = ramalan_zodiak[zodiak]
            
            # Tampilkan gambar zodiak
            print(f"\n🖼️  Membuka gambar zodiak {zodiak}...")
            tampilkan_gambar(data['gambar'])
            
            # Tampilkan hasil ramalan
            print("\n" + "="*70)
            print(f"                  ⭐ ZODIAK ANDA: {zodiak.upper()} ⭐")
            print("="*70)
            print(f"\n📅 Tanggal Lahir: {tanggal}/{bulan}")
            print(f"\n🔮 RAMALAN TAHUN 2026:\n")
            print(f"  💰 KEUANGAN:")
            print(f"     {data['keuangan']}\n")
            print(f"  💼 KARIR:")
            print(f"     {data['karir']}\n")
            print(f"  ❤️  ASMARA:")
            print(f"     {data['asmara']}")
            print("\n" + "="*70)
            
            # Simpan ke riwayat
            waktu_sekarang = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
            riwayat_ramalan.append({
                "Waktu": waktu_sekarang,
                "Tanggal_Lahir": tanggal,
                "Bulan_Lahir": bulan,
                "Zodiak": zodiak,
                "Gambar": data['gambar'],
                "Keuangan": data['keuangan'],
                "Karir": data['karir'],
                "Asmara": data['asmara']
            })
        else:
            print("\n❌ Kombinasi tanggal dan bulan tidak valid!")
            
    except ValueError:
        print("\n❌ Input harus berupa angka!")

def simpan_ke_csv():
    """Menu 2: Menyimpan riwayat ramalan ke file CSV"""
    if not riwayat_ramalan:
        print("\n⚠️  Belum ada riwayat ramalan untuk disimpan!")
        print("   Silakan cek ramalan terlebih dahulu (Menu 1)")
        return
    
    nama_file = input("\nMasukkan nama file CSV (tanpa .csv): ")
    nama_file = nama_file + ".csv"
    
    try:
        with open(nama_file, 'w', newline='', encoding='utf-8') as file:
            fieldnames = ["Waktu", "Tanggal_Lahir", "Bulan_Lahir", "Zodiak", 
                         "Gambar", "Keuangan", "Karir", "Asmara"]
            writer = csv.DictWriter(file, fieldnames=fieldnames)
            
            writer.writeheader()
            writer.writerows(riwayat_ramalan)
        
        print("\n" + "="*70)
        print(f"✅ Data berhasil disimpan ke file '{nama_file}'")
        print(f"📊 Total {len(riwayat_ramalan)} riwayat ramalan tersimpan")
        print("="*70)
        
    except Exception as e:
        print(f"\n❌ Gagal menyimpan file: {e}")

def tampilkan_menu():
    """Menampilkan menu utama dengan logo"""
    # Tampilkan logo zodiak
    tampilkan_logo_zodiak()
    
    print("\n" + "="*70)
    print("              ✨ APLIKASI RAMALAN ZODIAK 2026 ✨")
    print("="*70)
    print("  1. 🔮 Cek Ramalan Zodiak (Keuangan, Karir, Asmara)")
    print("  2. 💾 Simpan Riwayat ke CSV")
    print("  3. 🚪 Keluar")
    print("="*70)

def main():
    """Fungsi utama program"""
    print("\n" + "🌟"*35)
    print("       SELAMAT DATANG DI APLIKASI RAMALAN ZODIAK 2026")
    print("🌟"*35)
    
    print("\n📋 PERSIAPAN:")
    print("   Pastikan folder 'images' berisi:")
    print("   ✓ zodiac_logo.png (logo aplikasi di menu utama)")
    print("   ✓ 12 gambar zodiak: aries.png, taurus.png, gemini.png, cancer.png,")
    print("     leo.png, virgo.png, libra.png, scorpio.png, sagittarius.png,")
    print("     capricorn.png, aquarius.png, pisces.png\n")
    
    while True:
        tampilkan_menu()
        
        try:
            pilihan = input("\n👉 Pilih menu (1-3): ")
            
            if pilihan == "1":
                tampilkan_ramalan()
            elif pilihan == "2":
                simpan_ke_csv()
            elif pilihan == "3":
                print("\n" + "="*70)
                print("         ✨ Terima kasih telah menggunakan aplikasi ini! ✨")
                print("                      Sampai jumpa lagi! 👋")
                print("="*70 + "\n")
                break
            else:
                print("\n❌ Pilihan tidak valid! Silakan pilih menu 1-3.")
                
        except KeyboardInterrupt:
            print("\n\n⚠️  Program dihentikan oleh user.")
            break

if __name__ == "__main__":
    main()