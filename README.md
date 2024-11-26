# CLinkedList

тип листа - struct LinkedList*

создать лист - var = CreateList(int)

вывести весь лист - Display(struct LinkedList*)
вывести только ячейку, которая передана в параметры - DisplayOnlyThis(struct LinkedList*)

получить количество элементов - GetItemCount(struct LinkedList*)
получить получить значение по индексу - GetValue(struct LinkedList*, int)
получить ячейку по индексу - GetCellAtIndex(struct LinkedList*, int)
получить ячейку по значению - GetCellAtValue(struct LinkedList*, int)

добавить в начало - AddAtBeggin(struct LinkedList**, int)
добавить в конец - Append(struct LinkedList**, int)
добавить в произвольное место - Insert(struct LinkedList**, int, int)

удалить в начале - DeleteFirst(struct LinkedList**)
удалить в конце - DeleteLast(struct LinkedList**)
удалить по индексу - Delete(struct LinkedList**, int)
удалить по значению - Remove(struct LinkedList**, int)

удалить лист - DeleteList(struct LinkedList**)
