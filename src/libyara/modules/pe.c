/**
 * pe.c
 * https://github.com/VirusTotal/yara/blob/9a12a825846e1047916d03ec22f4768940dd95a0/libyara/modules/pe.c
 *  
 * @author five (i.f-ve@ya.ru)
 * @verison (2/20/2017)
 */
 
/**
 * pe_parse_certificates
 * @param PE* pe
 * @return null
 */
unsigned int __cdecl sub_4EC070(int a1)
{
  int v1; // eax@1
  int v2; // esi@1
  unsigned int result; // eax@2
  unsigned int v4; // ecx@4
  unsigned int v5; // edx@5
  int v6; // ebx@8
  unsigned int v7; // edx@8
  unsigned int v8; // ecx@9
  __int16 v9; // dx@11
  void *v10; // eax@15
  void *v11; // edi@15
  int v12; // eax@16
  void *v13; // eax@16
  int v14; // edi@17
  int v15; // ebx@18
  int v16; // eax@18
  int v17; // eax@18
  int v18; // ST10_4@18
  int v19; // eax@18
  int v20; // eax@18
  void *v21; // edx@18
  int *v22; // eax@18
  int *v23; // ebx@18
  int v24; // eax@18
  char *v25; // edi@19
  int v26; // eax@20
  int v27; // esi@20
  int v28; // ST10_4@27
  int v29; // eax@27
  int v30; // edx@27
  int v31; // ST10_4@27
  int v32; // eax@27
  int v33; // edx@27
  int v34; // [sp-14h] [bp-148h]@0
  int v35; // [sp-8h] [bp-13Ch]@21
  char *v36; // [sp+8h] [bp-12Ch]@19
  int v37; // [sp+Ch] [bp-128h]@18
  unsigned int v38; // [sp+10h] [bp-124h]@8
  void *v39; // [sp+14h] [bp-120h]@15
  int v40; // [sp+1Ch] [bp-118h]@1
  int v41; // [sp+20h] [bp-114h]@17
  void *v42; // [sp+24h] [bp-110h]@16
  int i; // [sp+28h] [bp-10Ch]@8
  char v44; // [sp+30h] [bp-104h]@18

  v1 = *(_DWORD *)(a1 + 8);
  v2 = 0;
  v40 = 0;
  if ( *(_WORD *)(v1 + 24) == 523 )
    result = v1 + 168;
  else
    result = v1 + 152;
  v4 = *(_DWORD *)result;
  if ( *(_DWORD *)result )
  {
    v5 = *(_DWORD *)(a1 + 4);
    if ( v4 <= v5 )
    {
      result = *(_DWORD *)(result + 4);
      if ( result <= v5 && result + v4 <= v5 )
      {
        v6 = v4 + *(_DWORD *)a1;
        v7 = result + v4 + *(_DWORD *)a1;
        v38 = v7;
        for ( i = v6; v6 + 9 <= v38; v7 = v38 )
        {
          v8 = *(_DWORD *)v6 + v6;
          if ( v8 > v7 )
            break;
          if ( !*(_DWORD *)v6 )
            break;
          v9 = *(_WORD *)(v6 + 4);
          if ( v9 != 256 && v9 != 512 )
            break;
          if ( v9 != 512 || *(_WORD *)(v6 + 6) != 2 )
          {
            v6 = v8 + (v8 & 7);
            i = v8 + (v8 & 7);
          }
          else
          {
            v10 = (void *)sub_5EED10(v6 + 8, *(_DWORD *)v6);
            v11 = v10;
            v39 = v10;
            if ( !v10 )
              break;
            v12 = sub_5EF490(v10, 0);
            v13 = (void *)sub_5EF4B0(v12, 0, 0);
            v42 = v13;
            if ( !v13 )
            {
              sub_5EE220(v11);
              break;
            }
            v14 = 0;
            v41 = 0;
            if ( sub_5EDF60(v13) > 0 )
            {
              do
              {
                v15 = sub_5EE080(v42, v14);
                v37 = v15;
                v16 = sub_5F0440(v15);
                sub_5EFFD0(v16, &v44, 0x100u);
                sub_4E01F0(&v44, strlen(&v44), *(_DWORD *)(a1 + 12), (int)"signatures[%i].issuer", v2);
                v17 = sub_5F0480(v15);
                sub_5EFFD0(v17, &v44, 0x100u);
                sub_4E01F0(&v44, strlen(&v44), *(_DWORD *)(a1 + 12), (int)"signatures[%i].subject", v2);
                v18 = *(_DWORD *)(a1 + 12);
                v19 = sub_5EEDD0(**(_DWORD **)v15);
                sub_4E0180(v19 + 1, (unsigned __int64)(v19 + 1) >> 32, v18, "signatures[%i].version");
                v20 = sub_5EF9A0(**(_DWORD **)(v15 + 4));
                v21 = (void *)sub_5EF7E0(v20);
                sub_4E01F0(v21, strlen((const char *)v21), *(_DWORD *)(a1 + 12), (int)"signatures[%i].algorithm", v2);
                v22 = (int *)sub_5F0470(v15);
                v23 = v22;
                v24 = *v22;
                if ( v24 > 0 )
                {
                  v25 = (char *)sub_4DDF80(3 * v24);
                  v36 = v25;
                  if ( v25 )
                  {
                    v26 = *v23;
                    v27 = 0;
                    if ( *v23 > 0 )
                    {
                      do
                      {
                        v35 = *(_BYTE *)(v27 + v23[2]);
                        if ( v27 >= v26 - 1 )
                          _snprintf(v25, 3u, "%02x", v35);
                        else
                          _snprintf(v25, 4u, "%02x:", v35);
                        v26 = *v23;
                        ++v27;
                        v25 += 3;
                      }
                      while ( v27 < *v23 );
                      v25 = v36;
                    }
                    v2 = v40;
                    sub_4E01F0(v25, strlen(v25), *(_DWORD *)(a1 + 12), (int)"signatures[%i].serial", v40);
                    sub_4DDF10(v25);
                  }
                }
                v28 = *(_DWORD *)(a1 + 12);
                v29 = sub_4E7A80(**(_DWORD **)(*(_DWORD *)v37 + 16));
                sub_4E0180(v29, v30, v28, "signatures[%i].not_before");
                v31 = *(_DWORD *)(a1 + 12);
                v32 = sub_4E7A80(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)v37 + 16) + 4));
                sub_4E0180(v32, v33, v31, "signatures[%i].not_after");
                v40 = ++v2;
                v14 = ++v41;
              }
              while ( v41 < sub_5EDF60(v42) );
              v6 = i;
            }
            v6 += *(_DWORD *)v6 + (((_BYTE)v6 + (unsigned __int8)*(_DWORD *)v6) & 7);
            i = v6;
            sub_5EE220(v39);
            sub_5EDDC0(v42);
          }
        }
        result = sub_4E0180(v34, (unsigned __int64)v2 >> 32, *(_DWORD *)(a1 + 12), "number_of_signatures");
      }
    }
  }
  return result;
}

/**
 * pe_parse_header
 *
 * @param PE* p
 * @param size_t base_address
 * @param int flags
 * @return null 
 */
unsigned int __cdecl sub_4EC470(int a1, int a2, char a3) 
{
  __int64 v3; // ST34_8@1
  __int64 v4; // ST14_8@1
  int v5; // eax@1
  int v6; // eax@2
  int v7; // edx@2
  bool v8; // cf@3
  int v9; // eax@4
  int v10; // ecx@5
  int v11; // eax@5
  int v12; // eax@7
  int v13; // eax@7
  int v14; // eax@7
  int v15; // eax@7
  int v16; // eax@7
  int v17; // eax@7
  int v18; // eax@7
  int v19; // eax@7
  int v20; // eax@7
  int v21; // ecx@7
  int v22; // edi@7
  unsigned int result; // eax@7
  signed int v24; // [sp+8h] [bp-18h]@9
  signed int i; // [sp+Ch] [bp-14h]@9
  char v26; // [sp+10h] [bp-10h]@11

  sub_4E0180(*(_WORD *)(*(_DWORD *)(a1 + 8) + 4), 0, *(_DWORD *)(a1 + 12), "machine");
  v3 = *(_WORD *)(*(_DWORD *)(a1 + 8) + 6);
  sub_4E0180(v3, HIDWORD(v3), *(_DWORD *)(a1 + 12), "number_of_sections");
  sub_4E0180(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 8), 0, *(_DWORD *)(a1 + 12), "timestamp");
  v4 = *(_WORD *)(*(_DWORD *)(a1 + 8) + 22);
  sub_4E0180(v4, HIDWORD(v4), *(_DWORD *)(a1 + 12), "characteristics");
  v5 = *(_DWORD *)(a1 + 8);
  if ( a3 & 2 )
  {
    v6 = *(_DWORD *)(v5 + 40) + a2;
    v7 = 0;
  }
  else
  {
    v8 = *(_WORD *)(v5 + 24) < 0x20Bu;
    v6 = sub_4ECE60(a1, *(_DWORD *)(v5 + 40), 0);
  }
  sub_4E0180(v6, v7, *(_DWORD *)(a1 + 12), "entry_point");
  v9 = *(_DWORD *)(a1 + 8);
  if ( *(_WORD *)(v9 + 24) == 523 )
  {
    v10 = *(_DWORD *)(v9 + 48);
    v11 = *(_DWORD *)(v9 + 52);
  }
  else
  {
    v10 = *(_DWORD *)(v9 + 52);
    v11 = 0;
  }
  sub_4E0180(v10, v11, *(_DWORD *)(a1 + 12), "image_base");
  v12 = *(_DWORD *)(a1 + 8);
  v8 = *(_WORD *)(v12 + 24) < 0x20Bu;
  sub_4E0180(*(_BYTE *)(v12 + 26), 0, *(_DWORD *)(a1 + 12), "linker_version.major");
  v13 = *(_DWORD *)(a1 + 8);
  v8 = *(_WORD *)(v13 + 24) < 0x20Bu;
  sub_4E0180(*(_BYTE *)(v13 + 27), 0, *(_DWORD *)(a1 + 12), "linker_version.minor");
  v14 = *(_DWORD *)(a1 + 8);
  v8 = *(_WORD *)(v14 + 24) < 0x20Bu;
  sub_4E0180(*(_WORD *)(v14 + 64), 0, *(_DWORD *)(a1 + 12), "os_version.major");
  v15 = *(_DWORD *)(a1 + 8);
  v8 = *(_WORD *)(v15 + 24) < 0x20Bu;
  sub_4E0180(*(_WORD *)(v15 + 66), 0, *(_DWORD *)(a1 + 12), "os_version.minor");
  v16 = *(_DWORD *)(a1 + 8);
  v8 = *(_WORD *)(v16 + 24) < 0x20Bu;
  sub_4E0180(*(_WORD *)(v16 + 68), 0, *(_DWORD *)(a1 + 12), "image_version.major");
  v17 = *(_DWORD *)(a1 + 8);
  v8 = *(_WORD *)(v17 + 24) < 0x20Bu;
  sub_4E0180(*(_WORD *)(v17 + 70), 0, *(_DWORD *)(a1 + 12), "image_version.minor");
  v18 = *(_DWORD *)(a1 + 8);
  v8 = *(_WORD *)(v18 + 24) < 0x20Bu;
  sub_4E0180(*(_WORD *)(v18 + 72), 0, *(_DWORD *)(a1 + 12), "subsystem_version.major");
  v19 = *(_DWORD *)(a1 + 8);
  v8 = *(_WORD *)(v19 + 24) < 0x20Bu;
  sub_4E0180(*(_WORD *)(v19 + 74), 0, *(_DWORD *)(a1 + 12), "subsystem_version.minor");
  v20 = *(_DWORD *)(a1 + 8);
  v8 = *(_WORD *)(v20 + 24) < 0x20Bu;
  sub_4E0180(*(_WORD *)(v20 + 92), 0, *(_DWORD *)(a1 + 12), "subsystem");
  sub_4EBF90(a1, sub_4EBD00, a1);
  sub_4E0180(*(_DWORD *)(a1 + 20), 0, *(_DWORD *)(a1 + 12), "number_of_resources");
  v21 = *(_DWORD *)(a1 + 8);
  v22 = *(_WORD *)(v21 + 20) + v21 + 24;
  result = *(_WORD *)(v21 + 6);
  if ( result >= 0x60 )
    result = 96;
  v24 = result;
  for ( i = 0; i < v24; ++i )
  {
    result = *(_DWORD *)a1 + *(_DWORD *)(a1 + 4);
    if ( v22 + 40 > result )
      break;
    sub_4F49D0(&v26, v22, 9);
    sub_4E01F0(&v26, strlen(&v26), *(_DWORD *)(a1 + 12), (int)"sections[%i].name", i);
    sub_4E0180(*(_DWORD *)(v22 + 36), 0, *(_DWORD *)(a1 + 12), "sections[%i].characteristics");
    sub_4E0180(*(_DWORD *)(v22 + 16), 0, *(_DWORD *)(a1 + 12), "sections[%i].raw_data_size");
    sub_4E0180(*(_DWORD *)(v22 + 20), 0, *(_DWORD *)(a1 + 12), "sections[%i].raw_data_offset");
    sub_4E0180(*(_DWORD *)(v22 + 12), 0, *(_DWORD *)(a1 + 12), "sections[%i].virtual_address");
    result = sub_4E0180(*(_DWORD *)(v22 + 8), 0, *(_DWORD *)(a1 + 12), "sections[%i].virtual_size");
    v22 += 40;
  }
  return result;
}
