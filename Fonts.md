# Fonts for Tesseract training

Tesseract training can use images made from text which was rendered with a list of fonts. Those fonts must be available on the host where the training process is running.

The required fonts are defined in training/language-specific.sh.

## Font installation

### Debian

On Debian GNU Linux and similar distributions (Linux Mint, Ubuntu, ...),
the required fonts can be installed like that:

    # AMHARIC_FONTS (todo)
    # ANCIENT_GREEK_FONTS (todo)
    # ARABIC_FONTS (todo)
    # ARMENIAN_FONTS (todo)
    # BENGALI_FONTS (todo)
    # BURMESE_FONTS (todo)
    # CHI_SIM_FONTS (todo)
    # CHI_TRA_FONTS (todo)
    # DEVANAGARI_FONTS (todo)
    # EARLY_LATIN_FONTS (todo)
    # FRAKTUR_FONTS (todo)
    # GEORGIAN_FONTS (todo)
    # GREEK_FONTS (todo)
    # GUJARATI_FONTS (todo)
    # HEBREW_FONTS (todo)
    # JPN_FONTS (todo)
    # KANNADA_FONTS (todo)
    # KHMER_FONTS (todo)
    # KOREAN_FONTS (todo)
    # KURDISH_FONTS (todo)
    # KYRGYZ_FONTS (todo)
    # LAOTHIAN_FONTS (todo)
    # LATIN_FONTS
    apt-get install fonts-dejavu gsfonts ttf-mscorefonts-installer
    # MALAYALAM_FONTS (todo)
    # NEOLATIN_FONTS (still incomplete)
    apt-get install fonts-ebgaramond fonts-gfs-didot fonts-gfs-didot-classic fonts-junicode
    # NORTH_AMERICAN_ABORIGINAL_FONTS (todo)
    # OLD_GEORGIAN_FONTS (todo)
    # ORIYA_FONTS (todo)
    # PERSIAN_FONTS (todo)
    # PUNJABI_FONTS (todo)
    # RUSSIAN_FONTS (todo)
    # SINHALA_FONTS (todo)
    # SYRIAC_FONTS (todo)
    # TAMIL_FONTS (todo)
    # TELUGU_FONTS (todo)
    # THAANA_FONTS (todo)
    # THAI_FONTS (todo)
    # TIBETAN_FONTS (todo)
    # VERTICAL_FONTS (todo)
    # VIETNAMESE_FONTS (todo)

The installed fonts are shown by the command `fc-list`. See also the [Debian wiki](https://wiki.debian.org/Fonts).

## Links to other sources of fonts

* https://fontlibrary.org/en (GFS Bodoni)
* https://fonts.google.com/
* http://scholarsfonts.net/cardofnt.html (Cardo)
* http://www.orbitals.com/self/ligature/ligature.htm (Wyld)
