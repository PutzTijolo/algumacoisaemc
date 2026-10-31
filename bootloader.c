__asm__(".code16gcc");
#define FONTE_BIOS ((unsigned char )0xFFA6E)
unsigned char cupreto = 0;
unsigned char cuazul = 0;

__attribute__((naked)) void _start() {
  asm("mov $0x0013,%ax");
  asm("int $0x10");
  asm("jmp main");
}

void vsync() {
  register unsigned char status asm("al");
  do {
    asm("mov $0x03da, %dx");
    asm("in %dx, %al");
  } while (!(status & 8));
}

void cocacolaespumante() {
  // pica de jegue no cu do elefante
  while(1){
    if (cupreto > 55){
      cupreto -= 16;
    }
    else if (cupreto < 32){
      cupreto += 32;
    }
    else{
      break;
    }
  }
}

int tecla() {
  register char abu asm("al");
  asm volatile("inb $0x60, %%al" : "=r"(abu));

  return abu;
}

void main() {
  volatile unsigned char *tela = (volatile unsigned char *)0xA0000;
  unsigned char interation = 0;
  while(1){
    if (tecla()==0x39){
      for(int y = 0; y < 100; y++){
      for(int x = 0; x < 100; x++){
         tela[((y + 50)*320) + (x + 105)] = 0x0F;
         cupreto = 0x00;
         cuazul = 0;
     }
  }
    }
    else{
      cuazul = 1;
     }
    for(int y = 0; y < 200; y++){
    for(int x = 0; x < 320; x++){
      if (cuazul==0){
        tela[(y * 320) + x] = cupreto;
      }
      else if (cuazul==1){
        cupreto = ((x*y)>>0);
        tela[(y * 320) + x] = cupreto + interation;
      }

     }
    }
    interation++;
  }

}


__attribute__((section(".boot_signature")))
const unsigned short assinatura_boot = 0xAA55;