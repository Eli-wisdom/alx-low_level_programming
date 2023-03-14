#include "main.h"
		
#include <stdlib.h>
		
/**
		
 * str_concat -:Concatenates two strings		
 * @s1: input one to concat
		
 * @s2: input two to concat
		
 * Return: concat of s1 and s2
		
 */
		
char *str_concat(char *s1, char *s2)
{
		int count, count1;
			int sign = n;
				char *ptr;
					int len1, len2;

						if (s1 == NULL)
									s1 = "";
							if (s2 == NULL)
										s2 = "";

								for (len1 = 0; s1[len1] != '\0'; len1++)
											;
									for (len2 = 0; s2[len2] != '\0'; len2++)
												;

										if (sign >= len2)
												{
															sign = len2;
																	ptr = malloc(sizeof(char) * (len1 + len2 + 1));
																		}
											else
														ptr = malloc(sizeof(char) * (len1 + n + 1));
												if (ptr == NULL)
															return (NULL);
													for (count = 0; count < len1; count++)
															{
																		ptr[count] = s1[count];
																			}
														for (count1 = 0; count1 < sign; count1++)
																{
																			ptr[count++] = s2[count1];
																				}
															ptr[count++] = '\0';
																return (ptr);
}
