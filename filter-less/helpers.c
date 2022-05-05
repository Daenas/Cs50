#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float Red = image[i][j].rgbtRed;
            float Green = image[i][j].rgbtGreen;
            float Blue = image[i][j].rgbtBlue;

            int average = round((Red + Green + Blue) / 3);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float Red = image[i][j].rgbtRed;
            float Green = image[i][j].rgbtGreen;
            float Blue = image[i][j].rgbtBlue;

            int sepiaRed = round(0.393 * Red + 0.769 * Green + 0.189 * Blue);
            int sepiaGreen = round(0.349 * Red + 0.686 * Green + 0.168 * Blue);
            int sepiaBlue = round(0.272 * Red + 0.534 * Green + 0.131 * Blue);

            if (sepiaRed > 255)
                sepiaRed = 255;
            if (sepiaGreen > 255)
                sepiaGreen = 255;
            if (sepiaBlue > 255)
                sepiaBlue = 255;

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int SomaRed = 0;
            int SomaBlue = 0;
            int SomaGreen = 0;
            float Qtd_Pixeis = 0;

            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }
                    SomaRed += image[currentX][currentY].rgbtRed;
                    SomaGreen += image[currentX][currentY].rgbtGreen;
                    SomaBlue += image[currentX][currentY].rgbtBlue;
                    Qtd_Pixeis++;
                }
                temp[i][j].rgbtRed = round(SomaRed / Qtd_Pixeis);
                temp[i][j].rgbtGreen = round(SomaGreen / Qtd_Pixeis);
                temp[i][j].rgbtBlue = round(SomaBlue / Qtd_Pixeis);
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}

/*
float SomaRed = 0;
float SomaBlue = 0;
float SomaGreen = 0;
float Qtd_Pixeis = 0;

if (image[i]< 0 && image[j] < 0)
{}
else
Qtd_Pixeis++;
int SomaRed = SomaRed + image[i][j].rgbtRed;
int SomaBlue = SomaBlue + image[i][j].rgbtBlue;
int SomaGreen = SomaGreen + image[i][j].rgbtGreen;

// Pixel atual[i][j].rgbtRed = Round(SomaRed/Qtd_Pixeis);
// Pixel atual[i][j].rgbtGreen = Round(SomaGreen/Qtd_Pixeis);
// Pixel atual[i][j].rgbtBlue = Round(SomaBlue/Qtd_Pixeis);



*/