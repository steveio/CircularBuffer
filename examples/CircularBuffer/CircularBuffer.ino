/**
 * Circular / Ring Buffer
 * 
 * 
 */

#include "CircularBuffer.h"

#define BUFFER_SIZE 3



void setup ()
{
  Serial.begin(115200);

}

void loop ()
{

  uint8_t * buffer  = malloc(BUFFER_SIZE * sizeof(uint8_t));

  Serial.println("\n=== C Circular Buffer Check ===\n");

  cbuf_handle_t cbuf = circular_buf_init(buffer, BUFFER_SIZE);

  Serial.println("Buffer initialized. ");
  print_buffer_status(cbuf);

  Serial.print("\n******\nAdding values: ");
  Serial.println(BUFFER_SIZE - 1);

  for(uint8_t i = 0; i < (BUFFER_SIZE - 1); i++)
  {
    circular_buf_put(cbuf, i);
    Serial.print("Added: ");
    Serial.print(i);
    Serial.print(" Size: ");
    Serial.print(circular_buf_size(cbuf));
  }

  print_buffer_status(cbuf);

  Serial.println("\n******\nAdding values:");
  for(uint8_t i = 0; i < BUFFER_SIZE; i++)
  {
    circular_buf_put(cbuf, i);
    Serial.print("Added: ");
    Serial.print(i);
    Serial.print(" Size: ");
    Serial.print(circular_buf_size(cbuf));
  }

  print_buffer_status(cbuf);

  Serial.println("\n******\nReading back values: ");
  while(!circular_buf_empty(cbuf))
  {
    uint8_t data;
    circular_buf_get(cbuf, &data);
    Serial.println(data);
  }
  Serial.println("\n");

  print_buffer_status(cbuf);


  delay(1000);

}

void print_buffer_status(cbuf_handle_t cbuf)
{
  Serial.print("Full: ");
  Serial.print(circular_buf_full(cbuf));

  Serial.print("Empty: ");
  Serial.print(circular_buf_empty(cbuf));

  Serial.print("Size: ");
  Serial.print(circular_buf_size(cbuf));

}
