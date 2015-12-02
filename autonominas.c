#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

float calcularSueldoBruto (float salarioBase, float plusGeneral, float plusNoSalarial, float plusPerceptible, float prorrateo, float prorrateoAUX, float horasExtra, float pagaExtraEsteMes);

int main() {
    int opcion=0;
    float salarioBase=0, prorrateo=0, prorrateoAUX=2, pagaExtraEsteMes=0,
        horasExtra=0, horas=0, dinero=0, plusPerceptible=0, plusGeneral=0,
        plusNoSalarial=0, porcentajeIRPF=0, salarioBruto=0, IRPF=0,
        salarioBaseIRPF=0, BCC=0, B=0, FP=0, BHE=0, TDSS=0, salarioNeto=0, plusAuxiliar=0;

    do{
        system("clear");

        printf("Elige el dato que quieras introducir:\n"
                "1- Salario base.\n"
                "2- ¿Está prorrateado durante el año?\n"
                "3- ¿Paga extra este mes?.\n"
                "4- Horas extra.\n"
                "5- Pluses percibido en prorrateo.\n"
                "6- Pluses salariales generales.\n"
                "7- Pluses no salariales.\n"
                "8- Porcentaje IRPF.\n"
                "9- ¡He terminado!\n"
                "0- Salir.\n\n");

        __fpurge(stdin);
        scanf("%i", &opcion);

        switch(opcion){
            case 0:
                system("clear");
                return EXIT_SUCCESS;

            case 1:
                printf("Salario base de: ");
                scanf("%f", &salarioBase);
                break;

            case 2:
                printf("1 para SÍ y 2 para NO: ");
                scanf("%f", &prorrateoAUX);
                break;

            case 3:
                printf("¿Este mes tiene paga extra? 1 para SÍ y 2 para NO: ");
                scanf("%f", &pagaExtraEsteMes);

                if(pagaExtraEsteMes == 2)
                    pagaExtraEsteMes = 0;

                break;

            case 4:
                printf("Cantidad de horas: ");
                scanf("%f", &horas);
                printf("Cantidad de dinero: ");
                scanf("%f", &dinero);
                break;

            case 5:
                printf("Cantidad: ");
                scanf("%f", &plusAuxiliar);
                plusPerceptible += plusAuxiliar;
                break;

            case 6:
                printf("Cantidad: ");
                scanf("%f", &plusAuxiliar);
                plusGeneral += plusAuxiliar;
                break;

            case 7:
                printf("Cantidad: ");
                scanf("%f", &plusAuxiliar);
                plusNoSalarial += plusAuxiliar;
                break;

            case 8:
                printf("Solo el numero del porcentaje: ");
                scanf("%f", &porcentajeIRPF);
                break;

            case 9:
                system("clear");
                break;

            default:
                break;
        }
    }while(opcion != 9);

    horasExtra = horas * dinero;

    /*Paso 2*/
    prorrateo = (salarioBase + plusPerceptible)*2/12;

    if (pagaExtraEsteMes == 1)
        pagaExtraEsteMes = prorrateo;

    /*Paso 1*/
    salarioBruto = calcularSueldoBruto(salarioBase, plusGeneral, plusNoSalarial, plusPerceptible, prorrateo, prorrateoAUX, horasExtra, pagaExtraEsteMes);
    printf("SalarioBruto: %.2f\n\n", salarioBruto);
    printf("Prorrateo: %.2f\n\n", prorrateo);

    if(prorrateoAUX == 1){
        /*Paso 3*/
        salarioBaseIRPF = salarioBase + plusGeneral + plusPerceptible + horasExtra + prorrateo;
        IRPF = porcentajeIRPF / 100 * salarioBaseIRPF;
        printf("IRPF: %.2f\n\n", IRPF);

        /*Paso 4*/
        BCC = (salarioBaseIRPF - horasExtra)*4.7/100;
        B = salarioBaseIRPF*1.55/100;
        FP = salarioBaseIRPF*0.1 / 100;
        BHE = horasExtra*4.7/100;
        printf("BCC: %.2f\n\n", BCC);
        printf("B: %.2f\n", B);
        printf("FP: %.2f\n\n", FP);
        printf("BHE: %.2f\n\n", BHE);
    }

    else{
        /*Paso 3*/
        salarioBaseIRPF = salarioBase + plusGeneral + plusPerceptible + horasExtra;
        IRPF = porcentajeIRPF / 100 * salarioBaseIRPF;
        printf("IRPF: %.2f\n\n", IRPF);

        /*Paso 4*/
        BCC = (salarioBaseIRPF - horasExtra + prorrateo)*4.7/100;
        B = (salarioBaseIRPF + prorrateo)*1.55/100;
        FP = (salarioBaseIRPF + prorrateo)*0.1 / 100;
        BHE = horasExtra*4.7/100;
        printf("BCC: %.2f\n\n", BCC);
        printf("B: %.2f\n", B);
        printf("FP: %.2f\n\n", FP);
        printf("BHE: %.2f\n\n", BHE);
    }

    /*Paso 5*/
    TDSS = BCC + B + FP + BHE;
    printf("TDSS: %.2f\n\n", TDSS);

    /*Paso 6*/
    salarioNeto = salarioBruto - IRPF - TDSS;
    printf("El salario neto será de %.2f\n\n", salarioNeto);

    return EXIT_SUCCESS;
}

float calcularSueldoBruto (float salarioBase, float plusGeneral, float plusNoSalarial, float plusPerceptible, float prorrateo, float prorrateoAUX, float horasExtra, float pagaExtraEsteMes){

    if(prorrateoAUX == 1)
        return salarioBase + plusGeneral + plusNoSalarial + plusPerceptible + horasExtra + prorrateo;

    else if(prorrateoAUX != 1 && pagaExtraEsteMes != 0)
        return salarioBase + plusGeneral + plusNoSalarial + plusPerceptible + horasExtra + pagaExtraEsteMes;

    else
        return salarioBase + plusGeneral + plusNoSalarial + plusPerceptible + horasExtra;
}
