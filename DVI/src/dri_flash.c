#include "main.h"

/** Flash_Program **/

#define FLASH_PAGE_SIZE        ((uint16_t)0x200)
#define FLASH_WRITE_START_ADDR ((uint32_t)0x08008000)
#define FLASH_WRITE_END_ADDR   ((uint32_t)0x08010000)

uint32_t Read_FLASH_MUIData(uint32_t address, uint8_t* buffer, uint32_t length);
FLASH_STS Flash_WriteStruct(uint32_t address, const uint8_t* data, uint32_t length);


/**
 * @brief 从Flash读取多个字节数据
 * @param address: 起始地址（必须是4字节对齐）
 * @param buffer: 数据缓冲区
 * @param length: 要读取的字节数
 * @return 成功读取的字节数
 */
uint32_t Read_FLASH_MUIData(uint32_t address, uint8_t* buffer, uint32_t length)
{
    uint32_t bytes_read = 0;
    uint32_t i;
    
    // 检查地址是否有效（在Flash范围内）
    if ((address < FLASH_WRITE_START_ADDR) || (address >= FLASH_WRITE_END_ADDR))
    {
        return 0; // 地址无效
    }
    
    // 按字节读取数据
    for (i = 0; i < length; i++)
    {
        // 确保地址不会越界
        if ((address + i) >= 0x08010000)
        {
            break;
        }
        
        // 直接读取内存地址的字节
        buffer[i] = *(volatile uint8_t*)(address + i);
        bytes_read++;
    }
    
    return bytes_read;
}
/**
 * @brief 向Flash写入多个字节数据
 * @param address: 起始地址（必须是4字节对齐）
 * @param data: 数据缓冲区
 * @param length: 要写入的字节数
 * @return FLASH_STS状态
 */
FLASH_STS Flash_WriteStruct(uint32_t address, const uint8_t* data, uint32_t length)
{
    FLASH_STS status = FLASH_EOP;
    uint32_t i;
    uint32_t temp_data;
    uint32_t bytes_to_write;
    
    // 检查地址是否有效
    if ((address < FLASH_WRITE_START_ADDR) || (address >= FLASH_WRITE_END_ADDR))
    {
        return FLASH_ERR_ADD; // 地址无效
    }
    
    // 检查地址是否为4字节对齐
    if ((address & 0x03) != 0)
    {
        return FLASH_ERR_ADD; // 地址不对齐
    }
    
    // 解锁Flash
    FLASH_Unlock();
    
    // 计算需要写入多少个完整的字
    uint32_t word_count = (length + 3) / 4; // 向上取整
    
    for (i = 0; i < word_count; i++)
    {
        uint32_t current_addr = address + (i * 4);
        
        // 确保地址不会越界
        if (current_addr >= 0x08010000)
        {
            status = FLASH_ERR_ADD;
            break;
        }
        
        // 组装32位数据
        temp_data = 0xFFFFFFFF; // 默认填充0xFF（擦除后的状态）
        bytes_to_write = (length - (i * 4));
        
        if (bytes_to_write > 4)
        {
            bytes_to_write = 4;
        }
        
        // 复制字节数据到32位变量
        for (uint32_t j = 0; j < bytes_to_write; j++)
        {
            temp_data &= ~(0xFF << (j * 8)); // 清除对应字节
            temp_data |= ((uint32_t)data[(i * 4) + j] << (j * 8)); // 设置字节
        }
        
        // 编程一个字
        status = FLASH_ProgramWord(current_addr, temp_data);
        
        if (status != FLASH_EOP)
        {
            break; // 编程失败，退出循环
        }
    }
    
    // 锁定Flash
    FLASH_Lock();
    
    return status;
}




















































