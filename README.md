Deskripsi Sistem Deteksi Asap Rokok Menggunakan ESP32
Sistem deteksi asap rokok berbasis ESP32 adalah alat yang dirancang untuk memantau kualitas udara di sekitar dan memberikan peringatan ketika terdeteksi adanya asap rokok. Sensor utama yang digunakan adalah MQ-2, yang mampu mendeteksi asap, gas berbahaya, dan perubahan konsentrasi partikulat di udara.
ESP32 berfungsi sebagai otak sistem, yang membaca data dari sensor dan memprosesnya berdasarkan ambang batas tertentu (misalnya nilai > 300 menandakan adanya asap rokok). Ketika konsentrasi asap melebihi ambang tersebut, sistem akan mengaktifkan beberapa fitur seperti:
Lampu LED indikator untuk memberi tanda visual bahwa alat sedang menyala.
Buzzer sebagai alarm suara ketika asap rokok terdeteksi.
Pengiriman notifikasi ke aplikasi seperti Telegram atau sistem monitoring berbasis IoT.
Selain itu, ESP32 dapat terhubung ke WiFi sehingga data dapat dikirim secara real-time ke  bot Telegram untuk notifikasi otomatis. Hal ini membuat sistem sangat cocok digunakan di sekolah, kantor, ruang publik, atau ruangan yang menerapkan kawasan bebas rokok.
Dengan memanfaatkan teknologi IoT, sistem ini memberikan solusi yang efektif, responsif, dan mudah diperluas untuk membantu menjaga lingkungan tetap sehat dan bebas dari asap rokok.
