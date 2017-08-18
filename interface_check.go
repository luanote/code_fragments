type Class struct{
}
type Interfacer interface{
}

var _ Class = (*Interfacer)(nil)

