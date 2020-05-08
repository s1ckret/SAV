#include "Array.h"

#include "Log.h"

void Array::Resize(size_t size) {
    m_size = size;
    std::shared_ptr<Column> new_array(new Column[m_size], [](Column * ptr) {
        LOG_INFO("Delete[] from lamda");
        delete[] ptr;
    });
    m_array.swap(new_array);
}

Column & Array::operator[](size_t index) {
    return m_array.get()[index];
}

size_t Array::Size() const {
    return m_size;
}

int Array::GetMaxValue( ) const {
    int max = m_array.get()[0].Data();
    for ( auto it = Begin( ); it != End( ); it++ ) {
        if ( it->Data( ) > max ) {
            max = it->Data( );
        }
    }
    return max;
}

Column * Array::Begin() const {
    Column * beginColumn = nullptr;
    if (m_size) {
        beginColumn = &m_array.get()[0];
    }
    return beginColumn;
}

Column * Array::End() const {
    Column * endColumn = nullptr;
    if (m_size) {
        endColumn = &m_array.get()[m_size - 1];
    }
    endColumn++;
    return endColumn;
}