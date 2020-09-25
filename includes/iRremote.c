IRsend irsend(13);

volatile void comando_ar(int cmd)
{
    switch (cmd)
    {
    case (0):
        Serial.println("Desliga o Ar");
        irsend.sendRaw(desliga, sizeof(desliga) / sizeof(desliga[0]), khz);
        break;
    case (1):
        irsend.sendRaw(liga, sizeof(liga) / sizeof(liga[0]), khz);
        break;
    case (3):
        Serial.println("Diminui o Ar");
        temp_ar = temp_ar - 1;
        comando_ar(temp_ar);
        break;
    case (4):
        Serial.println("Aumenta o Ar");
        temp_ar = temp_ar + 1;
        comando_ar(temp_ar);
        break;
    case 17:
        Serial.println("Colocando o Ar em 17 C");
        irsend.sendRaw(ar17, sizeof(ar17) / sizeof(ar17[0]), khz);
        break;
    case 18:
        Serial.println("Colocando o Ar em 18 C");
        irsend.sendRaw(ar18, sizeof(ar18) / sizeof(ar18[0]), khz);
        break;
    case 19:
        Serial.println("Colocando o Ar em 19 C");
        irsend.sendRaw(ar19, sizeof(ar19) / sizeof(ar19[0]), khz);
        break;
    case 20:
        Serial.println("Colocando o Ar em 20 C");
        irsend.sendRaw(ar20, sizeof(ar20) / sizeof(ar20[0]), khz);
        break;
    case 21:
        Serial.println("Colocando o Ar em 21 C");
        irsend.sendRaw(ar21, sizeof(ar21) / sizeof(ar21[0]), khz);
        break;
    case 22:
        Serial.println("Colocando o Ar em 22 C");
        irsend.sendRaw(ar22, sizeof(ar22) / sizeof(ar22[0]), khz);
        break;
    case 23:
        Serial.println("Colocando o Ar em 23 C");
        irsend.sendRaw(ar23, sizeof(ar23) / sizeof(ar23[0]), khz);
        break;
    case 24:
        Serial.println("Colocando o Ar em 24 C");
        irsend.sendRaw(ar24, sizeof(ar24) / sizeof(ar24[0]), khz);
        break;
    case 25:
        Serial.println("Colocando o Ar em 25 C");
        irsend.sendRaw(ar25, sizeof(ar25) / sizeof(ar25[0]), khz);
        break;
    case 26:
        Serial.println("Colocando o Ar em 26 C");
        irsend.sendRaw(ar26, sizeof(ar26) / sizeof(ar26[0]), khz);
        break;
    case 27:
        Serial.println("Colocando o Ar em 27 C");
        irsend.sendRaw(ar27, sizeof(ar27) / sizeof(ar27[0]), khz);
        break;
    case 28:
        Serial.println("Colocando o Ar em 28 C");
        irsend.sendRaw(ar28, sizeof(ar28) / sizeof(ar28[0]), khz);
        break;
    default:
        Serial.println("Comando desconhecido");
        break;
    }
}