#include <stdio.h>

int main()

{
    FILE *fp1;

    double Height, Weight, BMI, IBW, ER, Carbohydrate1, Carbohydrate2, Protein1, Protein2, Fat1, Fat2;
    /*
    Height in Feet
    BMI = Body Mass Index
    IBW = Ideal Body Weight
    ER = Energy Required per Day

    All 1s are kcal/day
        2s are gm/day
    */

    int i, j = 4, k =4;
    int Work;
    fp1 = fopen("Diet List.txt","w");

    fprintf(fp1,"\t\tSpecially Automatic Nutritionist Device (S.A.N.D)\n\n");

    printf("\t\t\tPlease Input Users Height, Weight and working Type:\n");

    printf("\t\t--------------------------------------------------------------\n");
    printf("\t\t1. Light Work");
    printf("\t\t2. Moderate Work");
    printf("\t\t3. Heavy Work\n\n\t\t");

    printf("Height: ");
    scanf("%lf", &Height);

    printf("\t\tWeight: ");
    scanf("%lf",&Weight);

    printf("\t\tWorking Type (1/2/3): ");
    scanf("%d",&Work);


    //BMI:
    Height = Height * 0.3048; //Changing Height in Meter

    BMI = Weight / (Height * Height);

    fprintf(fp1,"\t\tHeight = %0.2lf m\n\t\tWeight = %0.2lf kg\n\n\n", Height, Weight);
    fprintf(fp1, "\t\tBMI = %0.2lf kg per meter square\n\n", BMI);

    if (BMI <= 18.5)
            fprintf(fp1,"\t\tComment upon BMI: Underweight (less than 18.5)\n");

        else if ( BMI >18.5 && BMI <= 25)
                fprintf(fp1,"\t\tComment upon BMI: Normal (between 18.5 to 25)\n");

            else if (BMI > 25 && BMI <= 30)
                    fprintf(fp1,"\t\tComment upon BMI: Overweight (Between 25.01 to 30)\n");

                else
                        fprintf(fp1, "\t\tComment upon BMI: Obese (larger than 30)\n");


    //IBW:

    IBW = 21.75 * Height * Height;
    fprintf(fp1,"\n\n\t\tIdeal Body Weight = %0.2lf kg\n\n", IBW);

    //Energy Required

    switch (Work)

    {
        case 1:
            ER = IBW * 29;
            break;

        case 2:
            ER  = IBW * 33;
            break;


        default:
            ER = IBW * 37;
            break;
    }

    fprintf(fp1,"\n\n\t\tEnergy Requirement = %0.2lf kcal/day\n", ER);


    fprintf(fp1,"\n\n\t\tCalculation for Carbohydrate, Protein and Fat:\n\n");

    //Carbohydrate:

    Carbohydrate1 = (ER * 60) /100;
    Carbohydrate2 = Carbohydrate1 / 4;

    fprintf(fp1,"\t\tQuantity of Carbohydrate = %0.2lf kcal per day\n \t\t\tor %0.2lf gm of CHO\n\n", Carbohydrate1, Carbohydrate2);


    //Protein:

    Protein1 = (ER * 15) /100;
    Protein2 = Protein1 / 4;

    fprintf(fp1,"\t\tQuantity of Protein = %0.2lf kcal per day\n\t\t\t or %0.2lf gm of CNOH\n\n", Protein1, Protein2);

    //Fat:
    Fat1 = (ER * 25) /100;
    Fat2 = Fat1 / 9;

    fprintf(fp1,"\t\tQuantity of Fat = %0.2lf kcal per day\n\t\t\t or %0.2lf gm of Fat\n\n", Fat1, Fat2);



    //Calculation in Carbohydrate:

    fprintf(fp1,"\n\n\t\tCalculation for Carbohydrate:\n");
    fprintf(fp1,"\t\t--------------------------------\n");

    double acquired, low_fat_milk, bread, vegetables, fruits, low_con, high_con, sugar1, sugar;
    low_fat_milk = 12;
    bread = 15;
    vegetables = 5;
    fruits = 10;
    low_con = 3;
    high_con = 13;

    acquired = vegetables * j + fruits * k + low_fat_milk + low_con*2 + high_con ;

    bread = Carbohydrate2 - acquired;

    i = bread / 15.00;

    bread = 15 * i;
    vegetables = 5 * j;
    fruits = 10 * k;

    acquired = acquired + 15 * i;

    if (acquired > Carbohydrate2 - 50)
    {
        i++;
        bread = 15 * i;
    }

    sugar1 = (Carbohydrate2 - acquired);
    sugar = sugar1 / 10;

    fprintf(fp1,"\t\t----Name----------------Serving----------CHO(gm)\n");
    fprintf(fp1,"\t\tLow Fat Milk-------------- 1 -------------%0.2lf\n", low_fat_milk);
    fprintf(fp1,"\t\tBread--------------------- %d ------------%0.2lf\n",i, bread);
    fprintf(fp1,"\t\tVegetable----------------- %d -------------%0.2lf\n",j, vegetables);
    fprintf(fp1,"\t\tFruits-------------------- %d -------------%0.2lf\n",k, fruits);
    fprintf(fp1,"\t\tPulse (Low Concentreted)-- 2 -------------%0.2lf\n", low_con*2);
    fprintf(fp1,"\t\tPulse (High Concentreted)- 1 -------------%0.2lf\n", high_con);


    fprintf(fp1,"\n\n\t\tCarbohydrate Acquired = %0.2lf gm per day",acquired);

    fprintf(fp1,"\n\n\t\tCarbohydrate Required = % 0.2lfgm per day",Carbohydrate2);

    fprintf(fp1,"\n\t\tRest of the CHO will be covered from Sugar: %0.2lf serving size", sugar);



    //Calculation in Protein:

    fprintf(fp1,"\n\n\n\n\t\tCalculation for Protein:\n");
    fprintf(fp1,"\t\t------------------------\n");

    double eggs = 6.7, medium_fat = 7, low_fat = 7;
    double l, m, n;

    low_fat_milk = 8 ;
    bread = 2 * i;
    vegetables = 2 * j;
    low_con = 1 * 2 ;
    high_con = 5.4 ;


    acquired = low_fat_milk + bread + vegetables + low_con + high_con;


    if (acquired < Protein2)
    {
        l = 1;
        acquired = acquired + eggs;
        eggs = eggs * l;
    }
    else
    {
        l = 0;
        eggs = eggs * l;
    }




    medium_fat = 2*(Protein2 - acquired) / 3;
    m = medium_fat / 7;

    low_fat = (Protein2 - acquired) / 3;
    n = low_fat / 7;



    fprintf(fp1,"\t\t----Name----------------Serving--------CHON(gm)\n");
    fprintf(fp1,"\t\tLow Fat Milk---------------1-------------%0.2lf\n", low_fat_milk);
    fprintf(fp1,"\t\tBread----------------------%d------------%0.2lf\n",i, bread);
    fprintf(fp1,"\t\tVegetable------------------%d------------=%0.2lf\n",j, vegetables);
    fprintf(fp1,"\t\tPulse (Low Concentreted)---2-------------%0.2lf\n", low_con);
    fprintf(fp1,"\t\tPulse (High Concentreted)--1-------------%0.2lf\n",  high_con);
    fprintf(fp1,"\t\tEggs-----------------------%0.2lf----------%0.2lf\n",l, eggs);


    fprintf(fp1,"\n\n\t\tProtein Acquired = %0.2lf gm per day",acquired);

    fprintf(fp1,"\n\n\t\tProtein Required = %0.2lf gm per day",Protein2);

    fprintf(fp1,"\n\n\t\tRest of the CHON will be covered from Medium Fat and Low Fat:\n");
    fprintf(fp1,"\t\tMedium Fat-----------------%0.2lf-------------%0.2lf gm CHON\n",m, medium_fat);
    fprintf(fp1,"\t\tLow Fat--------------------%0.2lf-------------%0.2lf gm CHON\n",n, low_fat);






    //Calculation in Fat:


    fprintf(fp1,"\n\n\n\n\t\tCalculation for Fat:\n");
    fprintf(fp1,"\t\t------------------------\n");

    double oil, oil1;

    low_fat_milk = 5;
    eggs = 6.7 * l;
    medium_fat = 10 * m ;
    low_fat = 3 * n;


    acquired = low_fat_milk + eggs + medium_fat + low_fat;

    oil1 = Fat2 - acquired;
    oil = oil1 / 5;


    fprintf(fp1,"\t\t----Name----------------Serving----------Fat(gm)\n");
    fprintf(fp1,"\t\tLow Fat Milk---------------1--------------%0.2lf\n", low_fat_milk);
    fprintf(fp1,"\t\tEggs-----------------------%0.2lf-----------%0.2lf\n",l, eggs);
    fprintf(fp1,"\t\tMedium Fat-----------------%0.2lf-----------%0.2lf\n",m, medium_fat);
    fprintf(fp1,"\t\tLow Fat--------------------%0.2lf-----------%0.2lf\n",n, low_fat);



    fprintf(fp1,"\n\n\t\tFat Acquired = %0.2lf gm per day",acquired);

    fprintf(fp1,"\n\n\t\tFat Required = %0.2lf gm per day",Fat2);

    fprintf(fp1,"\n\n\t\tRest of the Fat will be covered from Oil: %0.2lf serving size \n", oil );



    //Breakfast

    fprintf(fp1,"\n\n\n\t\t\tBREAKFAST\n\n\n");

    double break_ruti, break_total;

    break_ruti = i / 4;

    if (i - (int)i != 0.00)
    {
        break_ruti = (int)break_ruti;
        break_ruti = break_ruti + 1;
    }




    break_total = break_ruti * 70 + 56 + l * 90 + 40 + 120;


    fprintf(fp1,"----Name------Serving------kcal--------------Description\n");
    fprintf(fp1,"----Ruti------- %0.2lf -------- %0.2lf ---------- %0.2lf pc medium size ata ruti\n", break_ruti,break_ruti*70,break_ruti);
    fprintf(fp1,"--Vegetables--- 2 --------- 56 ---------- 1cup ladies finger /cabbage /Potato /Any vegetable\n");
    fprintf(fp1,"----Egg------- %0.2lf ----- %0.2lf --------- 1 omlet hen's egg\n",l,l*90);
    fprintf(fp1,"----Fruit------ 1 --------- 40 ---------- 1 small sized Banana /Guava\n");
    fprintf(fp1,"----Milk------- 1 -------- 120 -----------1 glass 2 percent fat containing milk\n");

    fprintf(fp1,"\n\tTotal kcal in the Morning = %0.2lf kcal", break_total);



    //Mid-day Snack

    fprintf(fp1,"\n\n\n\t\t\tMID_DAY SNACK\n\n\n");

    fprintf(fp1,"----Name------Serving------kcal--------------Description\n");
    fprintf(fp1,"----Biscuit---- 0.5 ------- 45 ---------- 2 pc salted Biscuits\n");
    fprintf(fp1,"----Juice------ 1 --------- 90 ---------- 0.75 cup glass fruit juice\n");

    fprintf(fp1,"\n\tTotal kcal in the Mid-day Snack = 135 kcal");



    //Lunch

    double rice, lunch_total;

    rice = break_ruti + 1;

    lunch_total = rice * 70 + 56 + 72 + 150 + 40;

    fprintf(fp1,"\n\n\n\t\t\tLUNCH\n\n\n");

    fprintf(fp1,"----Name------Serving------kcal--------------Description\n");
    fprintf(fp1,"----Rice------- %0.0lf -------- %0.0lf --------== %0.1lf cup boiled rice\n",rice, rice*70, rice/2);
    fprintf(fp1,"--Vegetables--- 2 --------- 56 ---------- Any kind of plant vegetable\n");
    fprintf(fp1,"---Pulse------- 1 --------- 72 ---------- 0.5 cup high concentrated pulse of any kind\n");
    fprintf(fp1,"--Meat/Fish---- 2 -------- 150 ---------- 2pc medium fat containing chicken / fish \n");
    fprintf(fp1,"---Fruit------- 1 --------- 40 ---------- 1 medium sized orange / 6 pc olive amla\n");

    fprintf(fp1,"\n\tTotal kcal in the Lunch = %0.2lf kcal", lunch_total);



    //Afternoon

    double noodles = break_ruti -1;

    fprintf(fp1,"\n\n\n\t\t\tAFTERNOON\n\n\n");
    fprintf(fp1,"----Name------Serving------kcal--------------Description\n");
    fprintf(fp1,"---Noodles---- %0.0lf ---- %0.2lf ----------- %0.1lf cup cooked Noodles\n", noodles, noodles*80, noodles/2 );

    fprintf(fp1,"\n\tTotal kcal in the Afternoon = %0.2lf kcal", noodles * 80);



    //Dinner

    double dinner_ruti, dinner_total;

    dinner_ruti = break_ruti;

    dinner_total = dinner_ruti * 70 + 56 + 30 + 55 + 40;

    fprintf(fp1,"\n\n\n\t\t\tDINNER\n\n\n");
    fprintf(fp1,"----Name------Serving----kcal------------Description\n");
    fprintf(fp1,"----Ruti------- %0.0lf ------ %0.0lf -------- %0.0lf pc medium sized ata ruti \n", dinner_ruti, dinner_ruti * 70, dinner_ruti);
    fprintf(fp1,"--Vegetables--- 2 ------- 56 -------- 1 cup mixed vegetables vegetable\n");
    fprintf(fp1,"---Pulse------- 2 ------- 30 -------- 1 cup low concentrated pulse of any kind\n");
    fprintf(fp1,"--Meat/Fish---- 1 ------- 55 -------- low fat containing chicken / fish / meat \n");
    fprintf(fp1,"---Fruit------- 1 ------- 40 -------- 1 medium sized guava /apple / 1.5 cup popaya\n");


    fprintf(fp1,"\n\tTotal kcal in the Dinner = %0.2lf kcal", dinner_total);

    double x;
    x = break_total+135+lunch_total+noodles*80+dinner_total;

    fprintf(fp1,"\n\n\n\n\t\tSub Total kcal = (%0.2lf + 135 + %0.2lf + %0.2lf + %0.2lf) kcal",break_total, lunch_total, noodles * 80, dinner_total);
    fprintf(fp1,"\n\t\t\t       = %0.2lf kcal", x);

    double y;
    y = (int) oil * 45;

    fprintf(fp1,"\n\n\t\tOil = (%0.0lf * 45) kcal", oil);
    fprintf(fp1,"\n  \t\t    = %0.0lf kcal", y);

    double z;
    z = x + y;

    fprintf(fp1,"\n\n\t\tTotal kcal = (%0.0lf + %0.0lf) kcal",  x , y );
    fprintf(fp1,"\n  \t\t           = %0.0lf kcal", x + y );


    return 0;
}
