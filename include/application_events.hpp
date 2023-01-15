#ifndef APPLICATION_EVENTS_HPP
#define APPLICATION_EVENTS_HPP

template <typename T>
class EventEmitter{
    public:
    virtual ~EventEmitter()=default;
    virtual void AddSubscriber(EventHandler<T>* subscriber)=0;
    protected:
    virtual void Notify(const T& message) = 0;
};

template <typename T>
class EventHandler{
    public:
    friend class EventEmitter<T>;
    virtual ~EventHandler() = default;
    protected:
    virtual void Handle(const T& message) = 0;
};

#endif //APPLICATION_EVENTS_HPP