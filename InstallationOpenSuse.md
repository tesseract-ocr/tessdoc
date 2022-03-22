# Installation on openSUSE

## RHEL/CentOS/Scientific Linux, Fedora, openSUSE packages

* [Tesseract 4](https://build.opensuse.org/project/show/home:Alexander_Pozdnyakov)
* [Tesseract 5](https://build.opensuse.org/project/show/home:Alexander_Pozdnyakov:tesseract5)

### Installation commands for different platforms

For example, to install Tesseract with German language traineddata:

**For CentOS_8_Stream, run the following as root:**

```
sudo dnf config-manager --add-repo https://download.opensuse.org/repositories/home:/Alexander_Pozdnyakov:/tesseract5/CentOS_8_Stream/
sudo rpm --import https://build.opensuse.org/projects/home:Alexander_Pozdnyakov/public_key
sudo dnf install tesseract
sudo dnf install tesseract-langpack-*
```

**For CentOS 8, run the following as root:**
```
dnf config-manager --add-repo https://download.opensuse.org/repositories/home:/Alexander_Pozdnyakov/CentOS_8/
rpm --import https://build.opensuse.org/projects/home:Alexander_Pozdnyakov/public_key
dnf install tesseract
dnf install tesseract-langpack-deu
```

**For RHEL 7, run the following as root:**

```
yum-config-manager --add-repo https://download.opensuse.org/repositories/home:/Alexander_Pozdnyakov/RHEL_7/
yum update
yum install tesseract 
yum install tesseract-langpack-deu
```

**For CentOS 7, run the following as root:**
```
yum-config-manager --add-repo https://download.opensuse.org/repositories/home:/Alexander_Pozdnyakov/CentOS_7/
sudo rpm --import https://build.opensuse.org/projects/home:Alexander_Pozdnyakov/public_key
yum update
yum install tesseract 
yum install tesseract-langpack-deu
```

**For Scientific Linux 7, run the following as root:**
```
yum-config-manager --add-repo https://download.opensuse.org/repositories/home:/Alexander_Pozdnyakov/ScientificLinux_7/
yum update
yum install tesseract 
yum install tesseract-langpack-deu
```

**For Fedora 32, run the following as root:**
```
dnf config-manager --add-repo https://download.opensuse.org/repositories/home:Alexander_Pozdnyakov/Fedora_32/home:Alexander_Pozdnyakov.repo
dnf install tesseract
dnf install tesseract-langpack-deu
```

**For Fedora 31, run the following as root:**
```
dnf config-manager --add-repo https://download.opensuse.org/repositories/home:Alexander_Pozdnyakov/Fedora_31/home:Alexander_Pozdnyakov.repo
dnf install tesseract
dnf install tesseract-langpack-deu
```

**For openSUSE Tumbleweed, run the following as root:**
```
zypper addrepo https://download.opensuse.org/repositories/home:Alexander_Pozdnyakov/openSUSE_Tumbleweed/home:Alexander_Pozdnyakov.repo
zypper refresh
zypper install tesseract-ocr
zypper install tesseract-ocr-traineddata-german
```

**For openSUSE Leap 15.0, run the following as root:**
```
zypper addrepo https://download.opensuse.org/repositories/home:Alexander_Pozdnyakov/openSUSE_Leap_15.0/home:Alexander_Pozdnyakov.repo
zypper refresh
zypper install tesseract-ocr
zypper install tesseract-ocr-traineddata-german
```