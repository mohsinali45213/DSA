void strcom(char s1[50], char s2[50])
{
  int i = 0, m;
  while (s1[i] == s2[i])
  {
    if (s1[i] != '\0')
    {
      break;
    }
    i++;
  }

  m = s1[i] - s2[i];
  printf("M = %d", m);
  if (m == 0)
  {
    printf("Both string are equal");
  }
  else if (m < 0)
  {
    printf("First string appear befor sec");
  }
  else
  {
    printf("First string appear after sec");
  }
}
