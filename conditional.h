class Conditional: public SubExpression
{
public:
    Conditional(Expression* left, Expression* right, Expression* condition):
            SubExpression(left, right, condition)
    {
    }
    double evaluate()
    {
        return ((int)condition->evaluate()) ? (left->evaluate()) : (right->evaluate());
    }
};