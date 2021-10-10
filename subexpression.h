class SubExpression: public Expression
{
public:
    SubExpression(Expression *left);
    SubExpression(Expression* left, Expression* right);
    SubExpression(Expression* left, Expression* right, Expression* condition);

    static Expression* parse();
protected:
    Expression* left;
    Expression* right;
    Expression* condition;
};