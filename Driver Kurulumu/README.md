
# CH340G DRİVER

* Kartımızı USB kablosuyla bilgisayarımıza bağlıyoruz.

![image](https://user-images.githubusercontent.com/111511331/208234993-8f96a457-d9e9-4086-ab09-75f237e6e878.png)


* Kartı taktıktan sonra aygıt yöneticisini açıyoruz. Görüldüğü üzere kartımız için sürücü yüklenememiş ve hata mesajı mevcut. İndirdiğimiz sürücü dosyanın içindeki ch341ser.exe dosyasını çalıştırıyor ve çıkan pencereden INSTALL butonuna tıklıyoruz.

![image](https://user-images.githubusercontent.com/111511331/208235004-b11e6585-902f-49b9-8497-6a4774372b3c.png)


* INSTALL butonuna tıkladıktan sonra sürücüler yükleniyor ve “Driver install success!” yazan bir pencere çıkıyor.

![image](https://user-images.githubusercontent.com/111511331/208235014-ae0c9d38-05ab-4b62-bc93-645493952b5e.png)


* Bu sırada arkada Aygıt Yöneticisi açık ise, kartın sürücüsünün yüklendiğini ve Bağlantı Noktaları başlığı altında “USB-SERIAL CH340 (COM x)” şeklinde yer aldığını görebilirsiniz. Burada parantez içinde yazan kısım, kartımızın kullandığı COM portu numarasını göstermektedir.

![image](https://user-images.githubusercontent.com/111511331/208235105-0b889a78-7012-49e5-8c8e-af291cceb734.png)

Arduino IDE’de >>Araçlar >> Port kısmından buradaki COM portunun seçili olduğundan emin olduktan sonra NodeMCU’nuzu sorunsuz bir şekilde kullanabilirsiniz.

# CP2102 Driver 

* NodeMCU’nun bir diğer çipili versiyonu ise cp2102 versiyonudur. Genelde bu versiyona NodeMCU v3 denmektedir. Şimdi cp2102 driver nasıl yüklenir öğrenelim.

* Cp2102 driverı bilgisayarınıza yükledikten sonra, dosyanın içinde bulunan exe uzantılı dosyayı çalıştırıyoruz.

![image](https://user-images.githubusercontent.com/111511331/208235149-f0e591a1-29f0-464e-ae13-8ad538b2abf7.png)

* Daha sonra açılan setup penceresinde ileri butonuna tıklıyoruz.


![image](https://user-images.githubusercontent.com/111511331/208235154-b66f484a-79bd-49de-98c8-58f9dad48198.png)

* Son butonuna tıkladıktan sonra setup penceresi otamatik kapanacaktır, ve driverınız yüklenmiş olacaktır. Artık NodeMCUnuza Arduino IDE üzerinden sorunsuz bir şekilde kod yükleyebilirsiniz.
