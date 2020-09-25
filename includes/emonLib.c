EnergyMonitor SCT013;

void medicaoPotencia()
{
    int counter = 1;

    //Serial.println(xPortGetCoreID());
    // Calcula quantidade de tempo desde a última measurment realpower.
    double Irms1 = SCT013.calcIrms(1480);
    double Irms2 = SCT013.calcIrms(1480);
    double Irms3 = SCT013.calcIrms(1480);
    Irms = (Irms1 + Irms2 + Irms3) / 3;
    // Calcula o valor da Corrente
    //Serial.println("Irms = " + String(Irms, 2));
    if (Irms >= 0 and Irms <= 0.5)
    {
        Irms = 0;
        if (counter == 0)
        {
        }
        else
        {
            //enviar_info(0); COLOCAR O TIMER DE ENVIAR EM 0
        }
        counter = 0;
    }
    else
    {

        Irms = Irms;
        counter = 1;
    }

    potencia = Irms * tensao; // Calcula o valor da Potencia Instantanea
    // Calcular o número de hoje de kWh consumido.
    kwhTotal = kwhTotal + ((potencia / 1000.0) * 1.0 / 3600.0);
    Serial.println("Corrente:" + String(Irms) + "   Potencia:" + String(potencia) + "  Kwh:" + String(kwhTotal));
}